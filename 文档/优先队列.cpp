#include <iostream>
#include <bits/stdc++.h>
using namespace std;
// ���壺priority_queue<Type, Container, Functional>
// Type �����������ͣ�
// Container �����������ͣ�Container������������ʵ�ֵ�������
// ����vector,deque�ȵȣ��������� list��STL����Ĭ���õ���vector����
// Functional ���ǱȽϵķ�ʽ��

//�������       ��С����
priority_queue <int,vector<int>,greater<int> > q;
//�������       �Ӵ�С
priority_queue <int,vector<int>,less<int> >q;
//greater��less��stdʵ�ֵ������º���������ʹһ�����ʹ�ÿ���ȥ��һ��������
// ��ʵ�־�������ʵ��һ��operator()���������������ƺ�������Ϊ������һ���º������ˣ�

// top ���ʶ�ͷԪ��
// empty �����Ƿ�Ϊ��
// size ���ض�����Ԫ�ظ���
// push ����Ԫ�ص���β (������)
// emplace ԭ�ع���һ��Ԫ�ز��������
// pop ������ͷԪ��
// swap ��������