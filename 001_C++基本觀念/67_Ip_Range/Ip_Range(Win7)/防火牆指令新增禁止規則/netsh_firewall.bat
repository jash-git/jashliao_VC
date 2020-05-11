:: 防火牆指令新增禁止規則
:: netsh advfirewall firewall add rule name=disallow-111.111.111.111 action=block enable=yes localip=any dir=in profile=public remoteip=x.x.x.x-x.x.x.x
:: 47.153.128-191.*
netsh advfirewall firewall add rule name=disallow-47.153.128-191 action=block enable=yes localip=any dir=in profile=public remoteip=47.153.128.1-47.153.191.254
:: 58.14-25.*.*
netsh advfirewall firewall add rule name=disallow-58.14-25 action=block enable=yes localip=any dir=in profile=public remoteip=58.14.1.1-58.25.254.254
:: 58.30-63.*.*
netsh advfirewall firewall add rule name=disallow-58.30-63 action=block enable=yes localip=any dir=in profile=public remoteip=58.30.1.1-58.63.254.254
