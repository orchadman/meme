from Crypto.PublicKey import RSA
from Crypto.Signature import pkcs1_15
from Crypto.Hash import SHA256

# Key generation: Generate RSA key pair (2048 bits)
key = RSA.generate(2048)
private_key = key.export_key()  # Export the private key
public_key = key.publickey().export_key()  # Export the public key

# Print keys for reference
print("Private Key:", private_key.decode('ascii'))
print("Public Key:", public_key.decode('ascii'))

# Example documents: Original and modified content
original_document = b"This is the original document content"
modified_document = b"This is the modified document content"

# Hashing the documents using SHA-256
original_hash = SHA256.new(original_document)
modified_hash = SHA256.new(modified_document)

# Signing the original document's hash with the private key
private_key_object = RSA.import_key(private_key)
signature = pkcs1_15.new(private_key_object).sign(original_hash)

# Verifying the original document
try:
    public_key_object = RSA.import_key(public_key)
    pkcs1_15.new(public_key_object).verify(original_hash, signature)
    print("The signature for the original document is valid.")
except (ValueError, TypeError):
    print("The signature for the original document is invalid.")

# Verifying the modified document
try:
    pkcs1_15.new(public_key_object).verify(modified_hash, signature)
    print("The signature for the modified document is valid.")
except (ValueError, TypeError):
    print("The signature for the modified document is invalid.")
