#pragma once

namespace strings {
    constexpr size_t SHORT_BUFF = 16;

    class sso_common_string {
        size_t size_ {0};
        char *ptr {nullptr};
        union {
            char *data_;
            char buf_[SHORT_BUFF];
        } sso;

    public:
        explicit sso_common_string(const char* source) {
            if (source) {
                size_ = strlen(source);

                if (size_ < SHORT_BUFF) {
                    memcpy(sso.buf_, source, size_ + 1);
                    ptr = sso.buf_;
                } else {
                    sso.data_ = reinterpret_cast<char *>(malloc(size_));

                    if (sso.data_) {
                        memcpy(sso.data_, source, size_ + 1);
                    }
                    ptr = sso.data_;
                }
            }
        }

        ~sso_common_string() {
            if (sso.data_) {
                free(sso.data_);
            }
            size_ = 0;
        }
    };
}
