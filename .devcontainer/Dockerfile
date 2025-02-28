FROM ubuntu:latest AS builder

ENV CXY_ROOT="/home/dev/.cxy"
ENV PATH="$PATH:${CXY_ROOT}/bin"
ENV CXY_STDLIB_DIR="${CXY_ROOT}/lib/cxy/std"

# Install packages
RUN apt-get -y update && apt-get -y upgrade
RUN DEBIAN_FRONTEND=noninteractive apt-get install -y --fix-missing cmake sqlite3 libsqlite3-dev \
  libpq-dev postgresql postgresql-server-dev-all   \
  uuid-dev openssl libssl-dev build-essential \
  autoconf automake libtool curl make unzip wget \
  openssh-server nano rsync gdb bsdmainutils net-tools \
  libzmq3-dev git gcc g++ zsh sudo cppcheck clang llvm llvm-dev libclang-dev jq clang-format \
  ruby pkg-config libsystemd-dev libcap-dev

# Add user and home directory
RUN useradd -rm -d /home/dev -s /bin/zsh -g root -G sudo -u 1001 dev
RUN echo "dev:dev123" | chpasswd
USER dev
WORKDIR /home/dev

RUN sh -c "$(wget https://raw.githubusercontent.com/robbyrussell/oh-my-zsh/master/tools/install.sh -O -)"
RUN bash -c "$(wget https://raw.githubusercontent.com/dccarter/cstar/refs/heads/main/src/tools/download-cxy.sh -O -)"

