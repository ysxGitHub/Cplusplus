#include <mutex>
#include <string>
#include <thread>
#include <unistd.h>

// 日志上报Class
class ReportClass
{
private:
    ReportClass() {}
    ReportClass(const ReportClass&) = delete;
    ReportClass& operator=(const ReportClass&) = delete;
    ReportClass(const ReportClass&&) = delete;
    ReportClass& operator=(const ReportClass&&) = delete;

private:
    std::mutex mutex_;
    int count_ = 0;
    void addWorkThread();

public:
    void pushEvent(std::string event);

private:
    static void workThread(ReportClass *report);

private:
    static ReportClass* instance_;
    static std::mutex static_mutex_;

public:
    static ReportClass* GetInstance();
    static void ReleaseInstance();
};

std::mutex ReportClass::static_mutex_;
ReportClass* ReportClass::instance_;

ReportClass* ReportClass::GetInstance()
{
    // 单例简单实现，非本文重点
    std::lock_guard<std::mutex> lock(static_mutex_);
    if (instance_ == nullptr) {
        instance_ = new ReportClass();
        instance_->addWorkThread();
    }
    return instance_;
}

void ReportClass::ReleaseInstance()
{
    std::lock_guard<std::mutex> lock(static_mutex_);
    if(instance_ != nullptr)
    {
        delete instance_;
        instance_ = nullptr;
    }
}

// 轮询上报线程
void ReportClass::workThread(ReportClass *report)
{
    while(true)
    {
        // 线程运行过程中，report可能已经被销毁了
        std::unique_lock<std::mutex> lock(report->mutex_);
        if(report->count_ > 0)
        {
            report->count_--;
        }

        usleep(1000*1000);
    }
}

// 创建任务线程
void ReportClass::addWorkThread()
{
    std::thread new_thread(workThread, this);
    new_thread.detach();
}

// 外部调用
void ReportClass::pushEvent(std::string event)
{
    std::unique_lock<std::mutex> lock(mutex_);
    this->count_++;
}