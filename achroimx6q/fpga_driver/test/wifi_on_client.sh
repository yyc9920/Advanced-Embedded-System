ifconfig eth0 down
ifconfig wlan0 up

iwconfig wlan0 essid "Kideok'_iPhone"
wpa_supplicant -i wlan0 -c /etc/wpa_supplicant.conf &

ifconfig wlan0 172.20.10.5 netmask 255.255.255.240
route add default gw 172.20.10.1 dev wlan0

