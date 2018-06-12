#include "epoll.hpp"

int setnonblocking(int fd){ // 将文件描述符设置为非阻塞 
	
	int old_option = fcntl(fd, F_GETFL);
	int new_option = old_option | O_NONBLOCK;
	fcntl(fd, F_SETFL, new_option);
	return old_option;
}

void addfd(int epollfd, int fd, bool oneShot){

	epoll_event event;
	event.data.fd = fd;
	event.events = EPOLLIN | EPOLLET; // ET触发 
	if (oneShot) {

		event.events |= EPOLLONESHOT; 
	}
	epoll_ctl(epollfd, EPOLL_CTL_ADD, fd, &event);
	setnonblocking(fd);
}

void removefd(int epollfd, int fd){

	epoll_ctl(epollfd, EPOLL_CTL_DEL, fd, 0);
	close(fd);
}

void modfd(int epollfd, int fd, int ev){

	epoll_event event;
	event.data.fd = fd;
	event.events = ev | EPOLLET; // ET触发 
	epoll_ctl(epollfd, EPOLL_CTL_MOD, fd, &event);
}

int Epoll_create(int size){

	int rc;
	if ((rc = epoll_create(size)) < 0) {
		std::cout<<"epoll_crate failed"<<std::endl;
	}
	return rc; // 否则返回文件描述符 
}

int Epoll_wait(int epfd, struct epoll_event* events, int maxevents, int timeout){

	int rc;
	if ((rc = epoll_wait(epfd, events, maxevents, timeout)) == -1) {
		
		std::cout<<"epoll failed"<<std::endl;
	}
	return rc;
}
