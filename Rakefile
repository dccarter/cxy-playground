require 'fileutils'

CXY_BUILD_DIR=File.join(File.dirname(__FILE__), '.build')
CXY_DEPENCIES_DIR="#{CXY_BUILD_DIR}/deps"

CXY_DEPS_ARCH_DIR="#{CXY_DEPENCIES_DIR}/arch"
CXY_DEPS_ARCH_BIN_DIR="#{CXY_DEPS_ARCH_DIR}/bin"
CXY_DEPS_ARCH_LIB_DIR="#{CXY_DEPS_ARCH_DIR}/lib"

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


task :build do
  system "cxy build app.cxy --with-mm --build-dir #{CXY_BUILD_DIR} -o app -g"
end

task run: [:build] do
  system("#{CXY_BUILD_DIR}/app")
end

task :default => [:deps, :build]
