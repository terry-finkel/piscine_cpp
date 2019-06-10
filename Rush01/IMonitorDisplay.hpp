#ifndef IMONITORDISPLAY_HPP
# define IMONITORDISPLAY_HPP

class IMonitorDisplay {
public:
	virtual         ~IMonitorDisplay() {}
	virtual void    render() = 0;
};

#endif /* IMONITORDISPLAY_HPP */
