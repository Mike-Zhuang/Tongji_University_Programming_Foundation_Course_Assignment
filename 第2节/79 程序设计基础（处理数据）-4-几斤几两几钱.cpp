#include <iostream>
using namespace std;
int main() {
    int m_gram, m_jin, m_liang, m_qian;
    cout<<"单位为克的重量";
    cin>>m_gram;
    m_jin = m_gram / 500;
    m_liang = (m_gram-m_jin * 500) / 50;
    m_qian = (m_gram-m_jin * 500-m_liang * 50) / 5;
    cout<<m_jin<<"斤"<<m_liang<<"两"<<m_qian<<"钱。"<<endl;
    return 0;
}