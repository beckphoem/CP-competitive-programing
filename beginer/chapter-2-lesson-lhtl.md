# Bài 2: Biến và Toán Tử - "Những Chiếc Hộp Thần Kỳ"

Chào mừng bạn trở lại! Ở bài trước, chúng ta đã biết cách chào hỏi "người bạn" máy tính. Hôm nay, chúng ta sẽ học cách nhờ bạn ấy **ghi nhớ** và **tính toán** giúp mình.

Hãy tưởng tượng bộ não của máy tính giống như một **Kho Hàng Khổng Lồ**. Để cất giữ thông tin trong đó, chúng ta cần những **Chiếc Hộp**.

---

## 1. Biến (Variable) Là Gì?

**Ẩn dụ:** Biến chính là những **Chiếc Hộp Thần Kỳ** mà bạn tạo ra để đựng đồ đạc (thông tin).
-   Mỗi chiếc hộp chỉ chứa được **một giá trị** tại một thời điểm.
-   Nếu bạn bỏ cái mới vào, cái cũ sẽ biến mất!

```cpp
int a = 5; // Tạo một cái hộp tên là 'a', bỏ số 5 vào đó.
```

---

## 2. Quy Tắc Đặt Tên ("Chiếc Nhãn Dán")

Khi bạn có quá nhiều hộp trong kho, làm sao để biết hộp nào đựng gì? Bạn phải dán **Nhãn Tên** cho chúng.

**Quy tắc "Đặt tên cho Thú Cưng":**
1.  **Không dấu cách:** Tên phải viết liền. (Sai: `con meo`, Đúng: `conMeo` hoặc `con_meo`).
2.  **Không bắt đầu bằng số:** (Sai: `1conMeo`, Đúng: `conMeo1`).
3.  **Không dùng ký tự lạ:** Chỉ dùng chữ cái, số và dấu gạch dưới `_`. (Sai: `meo@#`, Đúng: `meo_cute`).
4.  **Phân biệt hoa thường:** `Meo` và `meo` là hai cái hộp khác nhau nhé!

> **Lời khuyên:** Hãy đặt tên sao cho nghe là hiểu ngay. Ví dụ `chieuDai`, `chieuRong` thay vì `a`, `b` vô nghĩa.

---

## 3. Kiểu Dữ Liệu ("Hình Dáng Chiếc Hộp")

Không phải hộp nào cũng giống nhau. Bạn không thể đổ nước vào hộp giấy, cũng không thể nhét con voi vào hộp diêm. Trong C++, mỗi loại dữ liệu cần một loại hộp riêng.

### a. `int` (Integer) - Hộp Vuông Nhỏ
-   **Đựng gì:** Số nguyên (không có dấu chấm). Ví dụ: 1, 10, -5, 100.
-   **Giới hạn:** Khoảng $\pm 2$ tỷ. Đủ dùng cho số lượng học sinh, số quả táo...
-   **Ví dụ:** `int soHocSinh = 40;`

### b. `long long` - Hộp Container Khổng Lồ
-   **Đựng gì:** Số nguyên **siêu to khổng lồ**.
-   **Khi nào dùng:** Khi `int` không chứa nổi (ví dụ tính tổng tiền tỷ phú, khoảng cách giữa các vì sao).
-   **Ví dụ:** `long long giaSan = 9000000000000LL;`

### c. `float` và `double` - Chai Nước
-   **Đựng gì:** Số thực (số có phần thập phân). Ví dụ: 3.14, 2.5, -9.8.
-   **Khác nhau:**
    -   `float`: Chai nước nhỏ, độ chính xác bình thường.
    -   `double`: Chai nước lớn, "kính lúp" soi kỹ hơn, độ chính xác cao gấp đôi `float`. **Khuyên dùng `double`** cho mọi bài toán tính toán số thực.
-   **Ví dụ:** `double diemToan = 8.5;`

### d. `char` (Character) - Hộp Đựng Nhẫn
-   **Đựng gì:** Đúng **một** ký tự duy nhất.
-   **Lưu ý:** Phải để trong dấu nháy đơn `' '`.
-   **Ví dụ:** `char xeploai = 'A';`

### e. `bool` (Boolean) - Công Tắc Đèn
-   **Đựng gì:** Chỉ 2 trạng thái: `true` (Đúng/Bật) hoặc `false` (Sai/Tắt).
-   **Ví dụ:** `bool troiDangMua = true;`

---

## 4. Toán Tử ("Cỗ Máy Chế Biến")

Sau khi có nguyên liệu trong hộp, chúng ta cần máy móc để chế biến chúng.

### Các Phép Toán Cơ Bản
-   `+` (Cộng), `-` (Trừ), `*` (Nhân), `/` (Chia).

### Lưu Ý Quan Trọng Về Phép Chia `/`
-   Nếu bạn lấy hai số nguyên chia cho nhau, máy tính sẽ **làm tròn xuống** (bỏ phần thập phân).
    -   Ví dụ: `5 / 2` sẽ bằng `2` (chứ không phải 2.5).
-   Muốn ra số thập phân, ít nhất một trong hai số phải là số thực.
    -   Ví dụ: `5.0 / 2` sẽ bằng `2.5`.

### Phép Chia Lấy Dư (`%`) - "Chiếc Đồng Hồ"
-   Ký hiệu `%` không phải là phần trăm đâu nhé! Nó là phép chia lấy phần dư.
-   **Ví dụ:**
    -   `5 % 2` bằng `1` (5 chia 2 được 2 dư 1).
    -   `10 % 3` bằng `1`.
-   **Ứng dụng:** Dùng để kiểm tra chẵn lẻ (số chia hết cho 2 thì dư 0), hoặc tính thời gian tuần hoàn.

---

---

## 5. Phép "Biến Hình" (Ép Kiểu - Type Casting)

Đôi khi, bạn muốn đổ nước từ chai (`double`) vào hộp vuông (`int`), hoặc ngược lại. Đây gọi là **Ép Kiểu**.

**Ẩn dụ:** Hãy tưởng tượng quy trình **Sang Chiết Chất Lỏng**.

### a. Ép kiểu tự động (Ngầm định) - "Đổ từ cốc nhỏ sang xô lớn"
Khi bạn gán số nhỏ vào hộp lớn, máy tính tự động chấp nhận vì không sợ tràn.
```cpp
int a = 5;
double b = a; // Ô kê luôn! b sẽ là 5.0
```

### b. Ép kiểu tường minh (Ép buộc) - "Cắt gọt cho vừa hộp"
Khi bạn muốn thế giới thực (số thực) chui vào hộp vuông (số nguyên), bạn phải dùng lực!
```cpp
double pi = 3.14;
int soNguyen = (int)pi; // Bắt buộc biến thành int!
// Kết quả: soNguyen là 3. (Phần đuôi .14 bị cắt bỏ không thương tiếc)
```

---

## 6. Phép Cộng Trừ Ký Tự (`char`) - "Cầu Thang Chữ Cái"

Bạn có biết `char` thực chất cũng là những con số bí mật? Máy tính dùng bảng mã ASCII để đánh số cho từng ký tự.
-   `'A'` là số 65.
-   `'B'` là số 66.
-   ...

**Ẩn dụ:** Hãy tưởng tượng Bảng Chữ Cái là một cái **Cầu Thang**.
-   Đứng ở bậc `'A'` (65), nếu bước lên 1 bậc (`+ 1`), bạn sẽ đến bậc `'B'` (66).

```cpp
char chuCai = 'A';
chuCai = chuCai + 1; // 65 + 1 = 66
cout << chuCai;      // In ra: B
```

**Mẹo:** Để biến chữ thường `'a'` thành chữ hoa `'A'`, bạn có thể dùng phép trừ: `'a' - 32 = 'A'`. (Khoảng cách giữa hoa và thường luôn là 32 bậc).

---

## 7. Bảo Bối "Kính Chiếu Yêu" (`typeid`)

Đôi khi nhìn vào một cái hộp, bạn quên mất nó thuộc loại gì. C++ cung cấp cho một chiếc "kính chiếu yêu" hoặc "máy quét mã vạch" tên là `typeid`.

-   Cần thêm thư viện: `#include <typeinfo>` (nhưng `bits/stdc++.h` đã bao gồm rồi).
-   Cần dùng lệnh: `typeid(tên_biến).name()`.

```cpp
int x = 10;
cout << typeid(x).name(); // Máy tính sẽ in ra ký hiệu loại hộp (ví dụ "i" cho int)
```
*Lưu ý: Tên hiển thị ("i", "d", "f"...) tùy thuộc vào trình biên dịch, nhưng đủ để bạn nhận diện.*

---



## 8. Ví Dụ Tổng Hợp

Đây là chương trình tính chu vi và diện tích hình chữ nhật:

```cpp
#include<bits/stdc++.h>
using namespace std;

int main(){ 
    // 1. Khai báo hộp (biến)
    int chieuDai = 10;
    int chieuRong = 5;

    // 2. Chế biến (Toán tử)
    int chuVi = (chieuDai + chieuRong) * 2;
    int dienTich = chieuDai * chieuRong;

    // 3. Xuất kho (In ra màn hình)
    cout << "Chu vi la: " << chuVi << endl;
    cout << "Dien tich la: " << dienTich << endl;
}
```

## Bài Tập Thử Thách
Bạn hãy thử viết chương trình tính tuổi của bạn vào năm 2050! (Gợi ý: Tạo biến `namSinh`, và dùng phép toán để tính).
