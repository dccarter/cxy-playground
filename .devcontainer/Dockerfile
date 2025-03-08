FROM suilteam/cxy:latest AS builder

# Install packages
RUN apt-get -y update && apt-get -y upgrade
RUN DEBIAN_FRONTEND=noninteractive apt-get install -y --fix-missing \
  ruby pkg-config libsystemd-dev libcap-dev
