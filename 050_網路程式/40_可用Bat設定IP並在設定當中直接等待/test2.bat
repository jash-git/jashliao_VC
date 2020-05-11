netsh interface ip set address name="區域連線" source=dhcp
netsh interface ip set dns name="區域連線" source=dhcp register=PRIMARY
netsh interface ip set wins name="區域連線" source=dhcp
exit
