// #include <sys / mman .h >
// #include < errno .h >
#include <string>
#include <stdexcept>
#include <iostream>
template <typename ElementType>
class VirtualMemoryContainer
{
private:
    size_t num_elements;
    ElementType *container;

public:
    VirtualMemoryContainer(size_t max_elements)
    {
        num_elements = max_elements;
        container = (ElementType *)mmap(nullptr, sizeof(ElementType) * max_elements, PROT_NONE,
                                        MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);
        if (container == (ElementType *)-1)
            throw vmc_error(errno);
        const int64_t block_size = 1048576;
        int64_t remaining = sizeof(ElementType) * max_elements;
        uint8_t *head = (uint8_t *)container;
        while (remaining > 0)
        {
            int ret = mprotect(head, std ::min(block_size, remaining), PROT_READ | PROT_WRITE);
            if (ret != 0)
                throw vmc_error(errno);
            head += block_size;
            remaining -= block_size;
        }
    }
    VirtualMemoryContainer(VirtualMemoryContainer &other) = delete;
    VirtualMemoryContainer(VirtualMemoryContainer &&other)
    {
        num_elements = other.num_elements;
        other.num_elements = 0;
        container = other.container;
        other.container = nullptr;
    }
    ˜ VirtualMemoryContainer()
    {
        if (container != nullptr)
        {
            int ret = munmap(container, sizeof(ElementType) * num_elements);
            if (ret != 0)
                throw vmc_error(errno);
        }
    }
    inline ElementType &operator[](size_t idx)
    {
        return container[idx];
    }
    inline const ElementType &operator[](size_t idx) const
    {
        return container[idx];
    }
    inline size_t size() const
    {
        return num_elements;
    }
};