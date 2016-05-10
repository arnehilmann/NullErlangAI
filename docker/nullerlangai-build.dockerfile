FROM arne/spring-build
MAINTAINER arne.hilmann@gmail.com
RUN apt-get install -y erlang-dev
RUN epmd -daemon
