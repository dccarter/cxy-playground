FROM suilteam/cxy:latest-ubuntu AS builder

# Install packages
RUN apt-get -y update && apt-get -y upgrade
RUN DEBIAN_FRONTEND=noninteractive apt-get install -y --fix-missing \
  ruby pkg-config libsystemd-dev libcap-dev

# Copy the source code
COPY . /cxy
WORKDIR /cxy
ENV ISOLATE_CONFIG=/usr/local/etc/isolate
RUN rake package

FROM suilteam/cxy:latest-ubuntu

# Build arguments
ARG RELEASE_TAG=v0.1.0

# Set environment variables
ENV RELEASE_TAG=${RELEASE_TAG}

# Set labels
LABEL version="${RELEASE_TAG}"

COPY --from=builder /cxy/.build/package /cxy
COPY --from=builder /cxy/.build/deps/arch/ /usr/local/
COPY --from=builder /usr/local/etc/isolate /usr/local/etc/isolate
ENV ISOLATE_CONFIG=/usr/local/etc/isolate
# Set working directory
WORKDIR /cxy
