#include <mutex>
#include <string>
#include <thread>
#include <unistd.h>


// 日志上报Class
class ReportClass: public std::enable_shared_from_this<ReportClass>
{
private:
    ReportClass() {}
    ReportClass(const ReportClass&) = delete;
    ReportClass& operator=(const ReportClass&) = delete;
    ReportClass(const ReportClass&&) = delete;
    ReportClass& operator=(const ReportClass&&) = delete;

private:
    static void workThread(std::weak_ptr<ReportClass> weak_report_ptr);

private:
    static std::shared_ptr<ReportClass> instance_;
    static std::mutex static_mutex_;

private:
    std::mutex mutex_;
    int count_ = 0;
    void addWorkThread();

public:
    static std::shared_ptr<ReportClass> GetInstance();
    static void ReleaseInstance();
};

std::mutex ReportClass::static_mutex_;
std::shared_ptr<ReportClass> ReportClass::instance_;

std::shared_ptr<ReportClass> ReportClass::GetInstance() {
    // 单例简单实现，非本文重点
    std::lock_guard<std::mutex> lock(static_mutex_);
    if (!instance_) {
        instance_ = std::shared_ptr<ReportClass>(new ReportClass());
        instance_->addWorkThread();
    }
    return instance_;
}

void ReportClass::ReleaseInstance() {
    std::lock_guard<std::mutex> lock(static_mutex_);
    if(instance_) {
        instance_.reset();
    }
}

// 轮询上报线程
void ReportClass::workThread(std::weak_ptr<ReportClass> weak_report_ptr) {
    while(true) {
        // 通过调用 w.lock() 方法得到一个用于管理 weak_ptr 对象所监测的资源的共享智能指针对象，使用这个对象初始化 shared_report_ptr。如果 use_count() 为0, 返回一个空shared_ptr; 否则返回一个指向 w 的对象的 shared_ptr 。
        std::shared_ptr<ReportClass> shared_report_ptr = weak_report_ptr.lock();
        if(!shared_report_ptr) {
            return;
        }

        std::unique_lock<std::mutex>(shared_report_ptr->mutex_);

        if(shared_report_ptr->count_ > 0) {
            shared_report_ptr->count_--;
        }

        usleep(1000*1000);
    }
}

// 创建任务线程
void ReportClass::addWorkThread() {
    std::weak_ptr<ReportClass> weak_report_ptr = shared_from_this();
    std::thread work_thread(workThread, weak_report_ptr);
    work_thread.detach();
}

// 外部调用
void ReportClass::pushEvent(std::string event) {
    std::unique_lock<std::mutex> lock(mutex_);
    this->count_++;
}

