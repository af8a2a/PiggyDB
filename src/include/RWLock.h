//
// Created by ame on 2023/4/28.
//

#ifndef PIGGYDB_RWLOCK_H
#define PIGGYDB_RWLOCK_H


#include <mutex>  // NOLINT
#include <shared_mutex>

/**
 * Reader-Writer latch backed by std::mutex.
 */
class ReaderWriterLatch {
public:
    /**
     * Acquire a write latch.
     */
    void WLock() { mutex_.lock(); }

    /**
     * Release a write latch.
     */
    void WUnlock() { mutex_.unlock(); }

    /**
     * Acquire a read latch.
     */
    void RLock() { mutex_.lock_shared(); }

    /**
     * Release a read latch.
     */
    void RUnlock() { mutex_.unlock_shared(); }

private:
    std::shared_mutex mutex_;
};


#endif //PIGGYDB_RWLOCK_H
