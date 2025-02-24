#ifndef CIPHER_HPP
#define CIPHER_HPP

#include <cstdint>
#include <vector>
#include <string>

using bytevec_t = std::vector<uint8_t>;

class Cipher {

enum mode_t {
    ECB,
    CBC,
    CFB, 
    OFB,
    CTR
};

public:
    Cipher();
    ~Cipher();

    void SetKey(bytevec_t &key) noexcept { this->key = key; }
    void SetMode(Cipher::mode_t mode) noexcept { this->mode = mode; }

    bytevec_t &ProcessBlockEncrypt(bytevec_t &data, bool isFinalBlock, std::string &padding);
    bytevec_t &ProcessBlockDecrypt(bytevec_t &data, bool isFinalBlock, std::string &padding);

    std::vector<uint8_t> &Encrypt(bytevec_t &data, bytevec_t& iv);
    bytevec_t &Decrypt(bytevec_t &data, bytevec_t& iv);

private:
    bytevec_t &BlockCipherEncrypt(bytevec_t &data);
    bytevec_t &BlockCipherDecrypt(bytevec_t &data);

    mode_t mode;
    bytevec_t key;
};

#endif // CIPHER_HPP
