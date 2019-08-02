FROM debian:sid-slim

LABEL "victim"

RUN 	apt-get -y update \
	apt-get install -y vim curl iptables \
	lsof netstat tcpdump dnsutils

RUN	echo "victim" > /etc/hostname

ENTRYPOINT ["sleep 10h"]
