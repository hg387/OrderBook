# OrderBook

This repo contains data structures to store market data in the below format. In future, this project could be extended to add matching orders and other orderbook functionalities.

```
<SYMBOL> <BID_PRICE> <ASK_PRICE> <BID_SIZE> <ASK_SIZE>
```

# Instructions to build and run:
1) This project is using CMake to build. Also, some functions available in C++20 are used. Example CMake command to build the project, the command should be adjusted according to build environment:
```
usr/bin/cmake -DCMAKE_INSTALL_PREFIX=/workspaces/OrderBook/out/install/orderbook -DCMAKE_C_COMPILER=/usr/bin/clang -DCMAKE_CXX_COMPILER=/usr/bin/clang++ -DCMAKE_BUILD_TYPE=Debug -S/workspaces/OrderBook -B/workspaces/OrderBook/out/build/orderbook
```

2) Based on the above build directory, example CMake command to run the project, the command should be adjusted according to build environment:
```
/usr/bin/cmake --build /workspaces/OrderBook/out/build/orderbook --parallel 4 --target orderbook --

3) The program is reading `input.txt` file presented under the project base directory. CMake is configured to copy the file if changed so please feel free to make changes in the input.txt file and run the program for any testing.
```

# Instructions to build and run tests:
1) We are using Google Test to create unit tests. Also, some functions available in C++20 are used. Example CMake command to build the project, the command should be adjusted according to build environment:
```
/usr/bin/cmake --build /workspaces/OrderBook/out/build/orderbook --parallel 4 --
``` 

2) Based on the above build directory, example CMake command to run the project, the command should be adjusted according to build environment:
```
cd /workspaces/OrderBook/out/build/orderbook && /usr/bin/ctest
```

# Approach
- The approach for storing market data is to use Tree Map like data structure which is available as `std::map` with custom sorting for buy and sell side respectively. The insertion and lookup of entries take `O(logN)` 

- OrderBook also has priorityQueues for buy and sell side respectively. These queues help in quickly `O(1)` lookup top of order books. Also, these would be helpful in implementing matching orders functionality of the orderbook in future.