FROM suilteam/cxy:latest-ubuntu AS builder

# Install packages
RUN apt-get -y update && apt-get -y upgrade
RUN DEBIAN_FRONTEND=noninteractive apt-get install -y --fix-missing \
  pkg-config libsystemd-dev libcap-dev

# Copy the source code
COPY . /cxy
WORKDIR /cxy
ENV ISOLATE_CONFIG=/usr/local/etc/isolate
RUN cxy package run release --no-cache

FROM suilteam/cxy:latest-ubuntu

COPY --from=builder /cxy/.cxy/artifacts /cxy
COPY --from=builder /cxy/.cxy/deps/arch/ /usr/local/
COPY --from=builder /usr/local/etc/isolate /usr/local/etc/isolate
ENV ISOLATE_CONFIG=/usr/local/etc/isolate
# Set working directory
WORKDIR /cxy
