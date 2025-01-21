# port_sniffer
This is port sniffer created with the boost asio library





## Run on Ubuntu or WSL 




sudo apt install libboost-all-dev


mkdir -p build
cd build
cmake ..
make


./network_port_sniffer <listen_ip> <port>


./network_port_sniffer 0.0.0.0 8080



## test sniffer


curl http://<listen_ip>:8080
echo "Hello" | nc <listen_ip> 8080