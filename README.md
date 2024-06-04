# vencrypt
## A Simple File Encryption Tool

vencrypt is a C program that allows you to encrypt and decrypt files using a user-provided password. It offers a basic level of encryption for educational purposes.

## Features:

- Encrypts and decrypts files using a password.
- Supports both encryption and decryption modes.
- Provides clear command-line options for ease of use.

*Important Note:*

*This program utilizes a rudimentary encryption technique and should not be considered secure for sensitive data. For robust encryption, explore industry-standard libraries or algorithms.*

## Usage:

### Compiling:

```
gcc vencrypt.c -o vencrypt
```

### Encryption:

```
./vencrypt E <input_file> <output_file>
```

Replace <input_file> with the path to the file you want to encrypt.
Replace <output_file> with the desired name for the encrypted file.
### Decryption:

```
./vencrypt D <input_file> <output_file>
```

Replace <input_file> with the path to the encrypted file.
Replace <output_file> with the desired name for the decrypted file.
### Password Prompt:

During execution, the program will prompt you to enter a password. This password will be used for both encryption and decryption.

### Example:

To encrypt a file named secret.txt and save the encrypted output as secret_encrypted.txt, use the following command:

```
./vencrypt E secret.txt secret_encrypted.txt
```

### Limitations:

This implementation uses a simple Caesar cipher-like approach, which is not cryptographically secure for real-world applications.
The maximum password length is set to 30 characters (MAXPASSLEN).

### Contributing:

We welcome contributions to improve vencrypt. Feel free to submit pull requests for bug fixes, enhancements, or security improvements. However, keep in mind the program's educational purpose and the limitations of basic encryption techniques.

### Disclaimer:

The authors and maintainers of this program are not responsible for any misuse or security vulnerabilities arising from its use. For secure file encryption, consider utilizing established cryptographic libraries or algorithms.