#pragma once

template <typename T>

//���� ������ ���·� singleton�� �����ϴ� ����
class Singleton
{
public:
    static T& Instance()
    {
        static T instance; 
        
        return instance;
    }

 
    Singleton(const Singleton&) = delete; //���� ������ 
    Singleton& operator=(const Singleton&) = delete; 

protected: //protected���� ����
    Singleton() = default;
    virtual ~Singleton() = default;
};