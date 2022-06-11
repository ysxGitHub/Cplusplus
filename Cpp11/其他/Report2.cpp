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
    ~ReportClass();

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

private:
    bool stop_ = false;
    std::thread *work_thread_;

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
        std::unique_lock<std::mutex> lock(report->mutex_);

        // 如果上报停止，不再轮询上报
        if(report->stop_)
        {
            break;
        }

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
    // 保存线程指针，不再使用分离线程
    work_thread_ = new std::thread(workThread, this);
}


ReportClass::~ReportClass()
{
    // 通过join来停止内部线程
    stop_ = true;
    work_thread_->join();
    delete work_thread_;
    work_thread_ = nullptr;
}

// 外部调用
void ReportClass::pushEvent(std::string event)
{
    std::unique_lock<std::mutex> lock(mutex_);
    this->count_++;
}