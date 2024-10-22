from Crypto.PublicKey import RSA
from Crypto.Cipher import PKCS1_OAEP
import binascii

# Generate RSA Key Pair
key_pair = RSA.generate(1024)
public_key = key_pair.publickey()

# Extract public key components
n = hex(public_key.n)
e = hex(public_key.e)
print("Public Key:")
print(f"n: {n}")
print(f"e: {e}")

# Export public key in PEM format
public_key_pem = public_key.exportKey()
print("Public Key PEM:")
print(public_key_pem.decode('ascii'))

# Extract private key components
d = hex(key_pair.d)
print("Private Key:")
print(f"d: {d}")

# Export private key in PEM format
private_key_pem = key_pair.exportKey()
print("Private Key PEM:")
print(private_key_pem.decode('ascii'))

# Message to be encrypted
msg = 'Ismile Academy'
msg_bytes = msg.encode('utf-8')

# Encrypt the message
encryptor = PKCS1_OAEP.new(public_key)
encrypted = encryptor.encrypt(msg_bytes)

# Convert encrypted message to hexadecimal
result = binascii.hexlify(encrypted)
print("Encrypted:")
print(result.decode('ascii'))

# Decrypt the message
decryptor = PKCS1_OAEP.new(key_pair)
decrypted = decryptor.decrypt(encrypted)

# Convert decrypted message to string
decrypted_msg = decrypted.decode('utf-8')
print("Decrypted Message:")
print(decrypted_msg)
