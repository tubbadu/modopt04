#ifndef INTERFACE_H
#define INTERFACE_H
enum color { RED=0, YELLOW=1, GREEN=2 };

struct light_if: virtual public sc_interface {
    virtual void set_main(color)=0; 
    virtual void set_sec(color)=0;
};
struct timer_if : virtual public sc_interface {
    virtual void wait_for_sec(unsigned int)=0;
};
struct car_if: virtual public sc_interface {
    virtual void wait_for_car()=0;
};
struct bus_if: public sc_interface {
    virtual sc_uint<32> read(sc_uint<32> addr)=0;
    virtual void write(sc_uint<32> addr, sc_uint<32> data)=0;
};
#endif
