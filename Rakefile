require 'fileutils'
require 'base64'
require 'net/http'
require 'json'

CXY_BUILD_DIR=File.join(File.dirname(__FILE__), '.build')
CXY_DEPENCIES_DIR="#{CXY_BUILD_DIR}/deps"

CXY_DEPS_ARCH_DIR="#{CXY_DEPENCIES_DIR}/arch"
CXY_DEPS_ARCH_BIN_DIR="#{CXY_DEPS_ARCH_DIR}/bin"
CXY_DEPS_ARCH_LIB_DIR="#{CXY_DEPS_ARCH_DIR}/lib"

CXY_PACKAGES_DIR="#{CXY_BUILD_DIR}/package"

ENV['PATH'] = "#{CXY_DEPS_ARCH_BIN_DIR}:#{ENV['PATH']}"

unless File.directory?(CXY_BUILD_DIR)
  FileUtils.mkdir_p(CXY_DEPENCIES_DIR)
end

def pullGitCode(repo, branch, dir)
  if File.directory?(dir)
    Dir.chdir(dir) do
      `git fetch --quiet`
    end
  else
    `git clone --depth 1 --branch #{branch} #{repo} #{dir}`
  end
end

depencies = {
  'isolate': {
    :repo => "https://github.com/ioi/isolate.git",
    :branch => "v2.0",
    :build => lambda do |dir|
      Dir.chdir(dir) do
        `make PREFIX=#{CXY_DEPS_ARCH_DIR} BOXDIR=#{CXY_DEPS_ARCH_DIR} install`
      end
    end
  }
}

task :deps do
  depencies.each do |name, dep|
    pullGitCode(dep[:repo], dep[:branch], "#{CXY_DEPENCIES_DIR}/#{name}")
    dep[:build].call("#{CXY_DEPENCIES_DIR}/#{name}")
  end
end


task build: [:deps] do
  system "cxy build app.cxy --with-mm --build-dir #{CXY_BUILD_DIR} -o app -g"
end

task run: [:build] do
  system("#{CXY_BUILD_DIR}/app")
end

task package: [:build, :test] do
  # We want to create a new package with the snippets,
  # snippets.json .build/app and .build/arch
  FileUtils.mkdir_p("#{CXY_PACKAGES_DIR}")
  FileUtils.cp_r("snippets", "#{CXY_PACKAGES_DIR}/snippets")
  FileUtils.cp("snippets.json", "#{CXY_PACKAGES_DIR}/snippets.json")
  FileUtils.cp(".build/app", "#{CXY_PACKAGES_DIR}/app")
end

task :clean do
  FileUtils.rm_rf(CXY_BUILD_DIR)
end

def runTest(snippet, command)
  # Reads snippet from snippets directory
  snippetPath = File.join("snippets", snippet)
  snippetContent = File.read(snippetPath)
  # encodes snippetContent to base64
  snippetContentBase64 = Base64.strict_encode64(snippetContent)
  # Sends an http post request to 0.0.0.0:8100 with the encoded snippet
  uri = URI.parse("http://0.0.0.0:8100/#{command}")
  http = Net::HTTP.new(uri.host, uri.port)
  request = Net::HTTP::Post.new(uri.request_uri)
  # Body is a json object { "source": snippetContentBase64, args: ""}
  request.body = { "code": snippetContentBase64, "args": "" }.to_json
  request["Content-Type"] = "application/json"
  response = http.request(request)
  # ensures the response is status is 200
  raise "Error: #{response.code} #{response.body}" unless response.code == "200"
  # The response should be a json object with the key "output"
  responseJson = JSON.parse(response.body)
  
  if command != "test" and responseJson["status"] != 0
    error = Base64.decode64(responseJson["stderr"])
    raise "Error: #{error}"
  end
  # Output should contain "Compilation success"
  output = Base64.decode64(responseJson["stdout"])
  raise "Error: #{output}" unless output.include?("Compilation success")
end

task :test do
  serverPid = Process.spawn("#{CXY_BUILD_DIR}/app")
  puts "Server started with pid #{serverPid}"
  # enumerate all files in the snippets directory and invoke runTest
  begin
    Dir.foreach("snippets") do |snippet|
      next if snippet.start_with?(".")
      puts "Running test for #{snippet}"
      begin
        if snippet.start_with?("test")
          runTest(snippet, "test")
        else
          runTest(snippet, "build")
        end
      rescue => e
        puts "Error: #{e}"
      end
    end
  ensure
    Process.kill("KILL", serverPid)
  end
end

task :default => [:deps, :build, :test]
