刚开始的使用是 IP 地址然后因为地址不够用所以引入了子网划分，发展之后又不够用了，采用 CIDR 进行优化，然后又采用 NAT 优化。

在 ipv4 被发明时具有时代局限性，所有的 ip 只有 42 亿左右。

# 最初的 IP 分类方案
**IP 地址 = 网络号 + 地址号**

****

将所有的 ip 地址分为 A、B、C、D、E 五类

其中 A、B、C 是单播地址，D 为多播地址，E 留到以后再使用

+ A 类地址网络号为 8 位且以 0 开头
+ B 类地址网络号为 16 位且以 10 开头
+ C 类地址网络号为 24 位且以 110 开头
+ D 类地址以 1110 开头
+ E 类地址以 1111 开头

在刚刚开始的那个年代，要求所有的每台主机、每个路由器接口被分配的 IP 地址都是全球唯一的。

路由器和路由器之间的接口可以不分配 ip，但是与其他节点连接的接口必须分配一个 ip

在一个网络中的所有主机的网络号必须是相同的，主机号可以自由分配

当一台新的主机接入该网络中时，需要给他分配一个 ip 并配置默认网关（就是接入互联网的路由器）

# 特殊的 ip 地址
这些特殊的 ip 地址都不能指派给一台主机或者路由器私用

| 网络号 | 主机号 | 作为分组源地址 | 作为分组目的地址 | 代表含义 |
| --- | --- | --- | --- | --- |
| 确定 | 全 0 | 不能 | 不能 | 表示整个网络（用于路由表、转发表） |
| 确定 | 全 1 | 不能 | 可以 | 向确定的网络号的网络广播 IP 分组 |
| 全 0 | 确定 | 可以 | 不能 | 表示本网络中的确定主机号的主机 |
| 全 0 | 全 0 | 可以 | 不能 | 表示本网络的本主机 |
| 全 1 | 全 1 | 不能 | 可以 | 向本网络广播 IP 分组 |
| 127 | 非全 0 或 1 | 可以 | 可以 | 环回自检地址。表示一台主机本身，用于本地软件环回检测 |


由上面的 1,2 条可以知道一个主机号位数为 n 位的网络主机数不能超过 2^n - 2 台。因为有两种特殊的不能用于分配主机。

3,4 条的作用是：在一个网络中新增一个主机时，因为此时主机没有分配到 ip 地址，没有代表自己的 ip，也不知道这个网络中的其他主机 ip，所以此时需要封装一个 DHCP 帧（该帧使用全 0 代表源地址 ip，使用全 1 代表目的地址）发送给 DHCP 服务器，然后 DHCP 服务器就可以给这个发送该帧的主机返回一个 DHCP 帧告诉它给它分配的 ip 地址。







