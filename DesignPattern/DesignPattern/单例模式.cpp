#include <iostream>
#include <chrono>
#include <thread>
#include <mutex>
#include <unistd.h>
using namespace std;
/*
����ģʽ����Դ�ڳ����ʼ���׶ξ���ɼ��أ��ռ任ʱ�䣩
��������ʵ�֣�
    ���þ�̬����������Դ�����ж�����ͬһ����Դ�������ʼ���׶������Դ������ֻ������һ��
    ���캯��˽�л� ����֤һ����ֻ��ʵ����һ������
*/
class UserManager {
private:
    // �����캯����Ϊ˽��
    UserManager() {};
    // ͬʱ�� copy ������ =���������� ����
    UserManager(const UserManager& obj) = delete;
    UserManager& operator=(const UserManager& obj) = delete;
public:
    static UserManager* GetInstance() {
        // ������̬�ֲ�����, C++11 ���ÿ����̰߳�ȫ
        static UserManager um;
        return &um;
    }
};

/*
����ģʽ����Դ��ʹ�õ�ʱ����ȥ���أ��ӳټ��أ�
    �������ָ�룬��ʼ��ԴΪ��
    static���Σ�����һ����Դ
    volatite���� ����ֹ�����������Ż�
    ��������  �̰߳�ȫ
    ���μ�⣬��ֹ����ͻ
*/

// �ֲ���̬��ָ�� Ҳ���̰߳�ȫ�� ���Բ��ü� m_mtx
class Singleton
{
public:
    static Singleton* GetInstance() {
        // ע������һ��Ҫʹ��Double-Check�ķ�ʽ���������ܱ�֤Ч�ʺ��̰߳�ȫ
        if (nullptr == m_pInstance) {//��һ���жϷ�ֹ��μ�����������ͻ
            m_mtx.lock();
            //�ڶ����ж��Ƿ�Ϊ�գ�Ϊ����Ϊ��һ�ε��ù��캯����������Ϊ�գ�������������ù��캯������������һ�δ����ҽ�����һ��
            if (nullptr == m_pInstance) {
                m_pInstance = new Singleton();
            }
            m_mtx.unlock();
        }
        return m_pInstance;
    }
    // ʵ��һ����Ƕ����������
    class CGarbo {
    public:
        ~CGarbo() {
            if (Singleton::m_pInstance)
                delete Singleton::m_pInstance;
        }
    };
    // ����һ����̬��Ա�������������ʱ��ϵͳ���Զ������������������Ӷ��ͷŵ�������
    static CGarbo Garbo;
private:
    // ���캯��˽��
    Singleton() {};
    // ������
    Singleton(Singleton const& obj);
    Singleton& operator=(Singleton const& obj);
    static Singleton* m_pInstance; // ��������ָ�� ��̬��Ա�������ڵ��ù��캯��ǰ�ȴ��������ж�
    static mutex m_mtx; //������
};
//��̬��Ա���������ʼ������һ�γ�ʼ��Ϊnullptr
Singleton* Singleton::m_pInstance = nullptr;
Singleton::CGarbo Garbo;
mutex Singleton::m_mtx;


int main(int argc, char const* argv[])
{
    UserManager* um1 = UserManager::GetInstance();
    UserManager* um2 = UserManager::GetInstance();
    cout << um1 << ", " << um2 << endl;
    Singleton* s1 = Singleton::GetInstance();
    Singleton* s2 = Singleton::GetInstance();
    cout << s1 << ", " << s2 << endl;

    pause();
    return 0;
}
