FROM arne/spring-build-base
MAINTAINER arne.hilmann@gmail.com
CMD /bin/bash
WORKDIR /src
RUN git clone git://github.com/spring/spring.git -b master
WORKDIR /src/spring
RUN git submodule sync
RUN git submodule update --init
RUN cmake -DCMAKE_INSTALL_PREFIX=/build/spring -DAI_TYPES=NATIVE .
RUN make install
