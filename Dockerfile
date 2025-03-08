FROM suilteam/cxy:latest AS builder

# Install packages
RUN apt-get -y update && apt-get -y upgrade
RUN DEBIAN_FRONTEND=noninteractive apt-get install -y --fix-missing \
  ruby pkg-config libsystemd-dev libcap-dev

# Copy the source code
COPY . /cxy
WORKDIR /cxy
RUN rake package

FROM suilteam/cxy:latest 
COPY --from=builder /cxy/.build/deps/arch/* /usr/local
COPY --from=builder /cxy/.build/package /cxy
# Set working directory
WORKDIR /cxy
