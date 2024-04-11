- 👋 Hi, I’m @LazzyZzZ
- 👀 I’m interested in ...
- 🌱 I’m currently learning ...
- 💞️ I’m looking to collaborate on ...
- 📫 How to reach me ...
- 😄 Pronouns: ...
- ⚡ Fun fact: ...

<!---
LazzyZzZ/LazzyZzZ is a ✨ special ✨ repository because its `README.md` (this file) appears on your GitHub profile.
You can click the Preview link to take a look at your changes.
--->
#include <iostream>
#include <bitset>

using namespace std;

// Hàm chuyển đổi từ hệ hex sang hệ nhị phân
string hex2bin(string s) {
    map<char, string> mp = {
        {'0', "0000"},
        {'1', "0001"},
        {'2', "0010"},
        {'3', "0011"},
        {'4', "0100"},
        {'5', "0101"},
        {'6', "0110"},
        {'7', "0111"},
        {'8', "1000"},
        {'9', "1001"},
        {'A', "1010"},
        {'B', "1011"},
        {'C', "1100"},
        {'D', "1101"},
        {'E', "1110"},
        {'F', "1111"}
    };
    string bin = "";
    for (char c : s) {
        bin += mp[c];
    }
    return bin;
}

// Hàm chuyển đổi từ hệ nhị phân sang hệ hex
string bin2hex(string s) {
    map<string, char> mp = {
        {"0000", '0'},
        {"0001", '1'},
        {"0010", '2'},
        {"0011", '3'},
        {"0100", '4'},
        {"0101", '5'},
        {"0110", '6'},
        {"0111", '7'},
        {"1000", '8'},
        {"1001", '9'},
        {"1010", 'A'},
        {"1011", 'B'},
        {"1100", 'C'},
        {"1101", 'D'},
        {"1110", 'E'},
        {"1111", 'F'}
    };
    string hex = "";
    for (int i = 0; i < s.length(); i += 4) {
        string ch = s.substr(i, 4);
        hex += mp[ch];
    }
    return hex;
}

// Hàm chuyển đổi từ hệ nhị phân sang thập phân
int bin2dec(string binary) {
    int decimal = 0;
    int power = 1;
    for (int i = binary.length() - 1; i >= 0; --i) {
        decimal += (binary[i] - '0') * power;
        power *= 2;
    }
    return decimal;
}

// Hàm chuyển đổi từ thập phân sang hệ nhị phân
string dec2bin(int num) {
    string binary = bitset<4>(num).to_string();
    return binary;
}

// Hàm hoán vị
string permute(string k, int arr[], int n) {
    string permutation = "";
    for (int i = 0; i < n; ++i) {
        permutation += k[arr[i] - 1];
    }
    return permutation;
}

// Hàm dịch trái
string shift_left(string k, int nth_shifts) {
    string s = "";
    for (int i = 0; i < nth_shifts; ++i) {
        s = k.substr(1) + k[0];
        k = s;
    }
    return k;
}

// Hàm XOR
string xor_func(string a, string b) {
    string ans = "";
    for (int i = 0; i < a.length(); ++i) {
        if (a[i] == b[i]) {
            ans += '0';
        } else {
            ans += '1';
        }
    }
    return ans;
}

// Bảng hoán vị ban đầu
int initial_permutation[] = {58, 50, 42, 34, 26, 18, 10, 2,
                              60, 52, 44, 36, 28, 20, 12, 4,
                              62, 54, 46, 38, 30, 22, 14, 6,
                              64, 56, 48, 40, 32, 24, 16, 8,
                              57, 49, 41, 33, 25, 17, 9, 1,
                              59, 51, 43, 35, 27, 19, 11, 3,
                              61, 53, 45, 37, 29, 21, 13, 5,
                              63, 55, 47, 39, 31, 23, 15, 7};

// Bảng hoán vị cuối cùng
int final_perm[] = {40, 8, 48, 16, 56, 24, 64, 32,
                    39, 7, 47, 15, 55, 23, 63, 31,
                    38, 6, 46, 14, 54, 22, 62, 30,
                    37, 5, 45, 13, 53, 21, 61, 29,
                    36, 4, 44, 12, 52, 20, 60, 28,
                    35, 3, 43, 11, 51, 19, 59, 27,
                    34, 2, 42, 10, 50, 18, 58, 26,
                    33, 1, 41, 9, 49, 17, 57, 25};

// Hàm mã hóa
string encrypt(string pt, string rkb[], string rk[]) {
    string plainText = hex2bin(pt);

    // Hoán vị ban đầu
    plainText = permute(plainText, initial_permutation, 64);
    cout << "Sau hoán vị ban đầu: " << bin2hex(plainText) << endl;

    // Chia nhóm
    string left = plainText.substr(0, 32);
    string right = plainText.substr(32, 32);

    for (int i = 0; i < 16; ++i) {
        // Mở rộng D-box
        string right_expanded = permute(right, exp_d, 48);

        // XOR với RoundKey[i]
        string xor_x = xor_func(right_expanded, rkb[i]);

        // S-boxes
        string sbox_str = "";
        for (int j = 0; j < 8; ++j) {
            int row = bin2dec(xor_x.substr(j * 6, 1) + xor_x.substr(j * 6 + 5, 1));
            int col = bin2dec(xor_x.substr(j * 6 + 1, 4));
            int val = sbox[j][row][col];
            sbox_str += dec2bin(val);
        }

        // Hoán vị cuối cùng
        sbox_str = permute(sbox_str, per, 32);

        // XOR với left
        string result = xor_func(left, sbox_str);
        left = result;

        // Hoán đổi
        if (i != 15) {
            swap(left, right);
        }
        cout << "Vòng " << i + 1 << ": " << bin2hex(left) << " " << bin2hex(right) << " " << rk[i] << endl;
    }

    // Kết hợp
    string combined = left + right;

    // Hoán vị cuối cùng
    string cipher_text = permute(combined, final_perm, 64);
    return cipher_text;
}

int main() {
    string pt = "123456ABCD132536"; // Plaintext
    string key = "AABB09182736CCDD"; // Key

    // Key generation
    // Chuyển đổi từ hệ hex sang hệ nhị phân
    key = hex2bin(key);

    // Loại bỏ các bit chẵn để tạo key 56 bit
    int keyp[] = {57, 49, 41, 33, 25, 17, 9,
                   1, 58, 50, 42, 34, 26, 18,
                  10, 2, 59, 51, 43, 35, 27,
                  19, 11, 3, 60, 52, 44, 36,
                  63, 55, 47, 39, 31, 23, 15,
                   7, 62, 54, 46, 38, 30, 22,
                  14, 6, 61, 53, 45, 37, 29,
                  21, 13, 5, 28, 20, 12, 4};
    key = permute(key, keyp, 56);

    // Số lần dịch trái
    int shift_table[] = {1, 1, 2, 2,
                          2, 2, 2, 2,
                          1, 2, 2, 2,
                          2, 2, 2, 1};

    // Bảng hoán vị key
    int key_comp[] = {14, 17, 11, 24, 1, 5,
                       3, 28, 15, 6, 21, 10,
                      23, 19, 12, 4, 26, 8,
                      16, 7, 27, 20, 13, 2,
                      41, 52, 31, 37, 47, 55,
                      30, 40, 51, 45, 33, 48,
                      44, 49, 39, 56, 34, 53,
                      46, 42, 50, 36, 29, 32};

    string left = key.substr(0, 28); // Chứa 28 bit cho RoundKeys trong nhị phân
    string right = key.substr(28, 28); // Chứa 28 bit cho RoundKeys trong hệ hex

    string rkb[16]; // RoundKeys trong nhị phân
    string rk[16]; // RoundKeys trong hệ hex

    for (int i = 0; i < 16; ++i) {
        // Dịch trái bit theo bảng dịch trái
        left = shift_left(left, shift_table[i]);
        right = shift_left(right, shift_table[i]);

        // Kết hợp left và right
        string combine_str = left + right;

        // Nén key từ 56 bit xuống 48 bit
        string round_key = permute(combine_str, key_comp, 48);

        rkb[i] = round_key;
        rk[i] = bin2hex(round_key);
    }

    cout << "Mã hóa" << endl;
    string cipher_text = encrypt(pt, rkb, rk);
    cout << "Văn bản mã hóa: " << cipher_text << endl;

    return 0;
}
