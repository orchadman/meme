from Crypto.PublicKey import RSA
from Crypto.Cipher import PKCS1_OAEP
import binascii
keyPair = RSA.generate(1024)
pubkey = keyPair.publickey()
n = hex(pubkey.n)
e = hex(pubkey.e)
print("Public Key: ")
print(n)
print(e)
pubkeyPEM = pubkey.export_key()
print(pubkeyPEM.decode('ascii'))
en = hex(keyPair.n)
d = hex(keyPair.d)
print("Private Key: ")
print(en)
print(d)
privkeyPEM = keyPair.export_key()
print(privkeyPEM.decode('ascii'))
omsg = 'Ismile Academy'
msg = omsg.encode('utf-8')
encryptor = PKCS1_OAEP.new(pubkey)
encrypted = encryptor.encrypt(msg)
result = binascii.hexlify(encrypted)
print("Encrypted: ", result)

