#!/bin/sh
### BEGIN INIT INFO
# Provides:		iptables
# Required-Start:
# Should-Start:
# Required-Stop:
# Should-Stop:
# Default-Start:	2 3 4 5
# Default-Stop:	 	0 1 6
# Short-description:	iptables
# Description: 		Firewall
### END INIT INFO
# start/stop iptables
#

# Réinitialise les règles
#sudo iptables -t filter -F
#sudo iptables -t filter -X 
 
# Bloque tout le trafic
sudo iptables -t filter -P INPUT DROP 
sudo iptables -t filter -P FORWARD DROP 
sudo iptables -t filter -P OUTPUT DROP 

# Autorise les connexions deja faites + accept pour update (security debian)
sudo iptables -A INPUT -m state --state RELATED,ESTABLISHED -j ACCEPT 
sudo iptables -A OUTPUT -m state --state RELATED,ESTABLISHED -j ACCEPT 
sudo iptables -A OUTPUT -p tcp --dport 53 -j ACCEPT
sudo iptables -A OUTPUT -p udp --dport 53 -j ACCEPT

# Localhost (loopback)
sudo iptables -t filter -A INPUT -i lo -j ACCEPT 
sudo iptables -t filter -A OUTPUT -o lo -j ACCEPT 
 
# ICMP (Ping)
sudo iptables -t filter -A INPUT -p icmp -j ACCEPT 
sudo iptables -t filter -A OUTPUT -p icmp -j ACCEPT 
 
# SSH
sudo iptables -t filter -A INPUT -p tcp --dport 5353 -j ACCEPT 
sudo iptables -t filter -A OUTPUT -p tcp --dport 5353 -j ACCEPT 
 
# HTTP
sudo iptables -t filter -A OUTPUT -p tcp --dport 80 -j ACCEPT 
sudo iptables -t filter -A INPUT -p tcp --dport 80 -j ACCEPT 

# HTTPS
sudo iptables -t filter -A OUTPUT -p tcp --dport 443 -j ACCEPT 
sudo iptables -t filter -A INPUT -p tcp --dport 443 -j ACCEPT 

#AGAINST DOS
sudo iptables -A INPUT -p tcp --syn -m limit --limit 1/second -j ACCEPT
sudo iptables -A INPUT -p udp -m limit --limit 1/second -j ACCEPT
sudo iptables -A INPUT -p icmp --icmp-type echo-request -m limit 1/second -j ACCEPT
sudo iptables -A INPUT -m conntrack --ctstate INVALID -j DROP

echo "set up rules firewall ....... [ok]"
#sudo sbin/ipatbles-save > /etc/firewall
