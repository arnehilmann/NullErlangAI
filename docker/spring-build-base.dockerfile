FROM ubuntu
MAINTAINER arne.hilmann@gmail.com
RUN apt-get update
RUN apt-get install -y build-essential cmake cmake-gui git
RUN apt-get install -y libglew-dev libsdl2-dev libdevil-dev libopenal-dev libogg-dev libvorbis-dev libfreetype6-dev p7zip-full libxcursor-dev libboost-thread-dev libboost-regex-dev libboost-system-dev libboost-program-options-dev libboost-signals-dev libboost-chrono-dev libboost-filesystem-dev libunwind8-dev curl libcurl4-openssl-dev
