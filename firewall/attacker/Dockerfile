FROM debian:sid-slim

LABEL "attacker"

RUN 	apt-get -y update \
	apt-get install -y vim curl iptables \
	lsof netstat tcpdump dnsutils \
	nmap

RUN	echo "attacker" > /etc/hostname

ENTRYPOINT ["sleep 10h"]
