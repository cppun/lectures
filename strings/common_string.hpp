#pragma once

namespace strings {

    class common_string {
    private:
        char* data_ {nullptr};
        size_t size_ {0};
        size_t capacity_ {0};

    public:
        explicit common_string(const char *source) {
            init_and_fill(source);
        }

        ~common_string() {
            if (data_) {
                free(data_);
            }
            size_ = 0;
            capacity_ = 0;
        }

        common_string(const common_string& source) {
            init_and_fill(source.data_);
        }

        common_string& operator=(const common_string& source) {
            if (&source != this) {
                if (source.size_ > capacity_) {
                    if (data_) {
                        free(data_);
                    }
                    init_and_fill(source.data_);
                } else {
                    for (size_t a = 0; a <= size_; ++a) {
                        data_[a] = source.data_[a];
                    }
                }
            }
            return *this;
        }

    private:
        void init_and_fill(const char* source) {
            if (source) {
                size_ = strlen(source);
                capacity_ = size_ * 2;
                data_ = reinterpret_cast<char *>(malloc(capacity_));

                if (data_) {
                    for (size_t a = 0; a <= size_; ++a) {
                        data_[a] = source[a];
                    }
                }
            }
        }
    };
}
