

#ifdef __cplusplus
extern "C" { 
#endif

	bool RijndaelEK_ECB_encrypt(const uint8_t* key, const uint8_t* plaintext, uint8_t* ciphertext);
	bool RijndaelEK_ECB_decrypt(const uint8_t* key, uint8_t* plaintext, const uint8_t* ciphertext);

	bool RijndaelEK_ECB_encrypt_buffer(const uint8_t* key, const uint8_t* plaintext, const size_t len, uint8_t* ciphertext);
	bool RijndaelEK_ECB_decrypt_buffer(const uint8_t* key, uint8_t* plaintext, const size_t len, const uint8_t* ciphertext);

	bool RijndaelEK_CTR_encrypt_buffer(const uint8_t* key, const uint8_t* nonce, const uint8_t* plaintext, const size_t len, uint8_t* ciphertext);
	bool RijndaelEK_CTR_decrypt_buffer(const uint8_t* key, const uint8_t* nonce, uint8_t* plaintext, const size_t len, const uint8_t* ciphertext);

	bool RijndaelEK_CTR_encrypt_buffer_offset(const uint8_t* key, const uint8_t* nonce, const uint8_t* counterStart, const uint8_t* plaintext, const size_t len, uint8_t* ciphertext);
	bool RijndaelEK_CTR_decrypt_buffer_offset(const uint8_t* key, const uint8_t* nonce, const uint8_t* counterStart, uint8_t* plaintext, const size_t len, const uint8_t* ciphertext);

	const uint8_t* RijndaelEK_counterStart_for_byte(const unsigned long offset);

#ifdef __cplusplus
}
#endif



