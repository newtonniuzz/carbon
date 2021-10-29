#ifndef __MOD_EGR_H__
#define __MOD_EGR_H__

#include "comm_def.h"

////////////////////////////////////////////////////////
// Project： SystemC虚拟项目
// Module:   mod_ing
// Description: mod_ing 入口ing模块h文件
// Group：预研组
// Author: Newton
// Date: 2021.10.14 第一版
// Hierarchy : 编号，索引公共库
////////////////////////////////////////////////////////
class mod_egr: public sc_module
{
public:
    mod_egr(sc_module_name name);
    SC_HAS_PROCESS(mod_egr);
    void rev_pkt_process(void);
    void send_pkt_process(void);

public:
    sc_in<s_pkt_desc> in_port;
    std::array<sc_out<s_pkt_desc> *, G_INTER_NUM> out_port;
    sc_in<int> in_clk_cnt;

    std::deque<s_pkt_desc> fifo_port;
    int pkt_count_port;

private:
    std::array<int, G_INTER_NUM> port_send_bytes;
    const int clk_gap;
    int clk_wait;
};
#endif // __MOD_EGR_H__
