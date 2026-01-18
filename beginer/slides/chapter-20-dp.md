Chào bạn! Tôi đã sẵn sàng cùng bạn bước vào thế giới của **Dynamic Programming (Quy hoạch động)**.

Dù bạn chưa tải lên một cuốn sách cụ thể, tôi sẽ đóng vai trò là "người dịch ý tưởng" dựa trên lộ trình chuẩn mực nhất để một học sinh cấp 2 có thể làm chủ tư duy này. Chúng ta sẽ không học vẹt công thức, mà sẽ học cách "xây dựng" tư duy.

---

## 🗺️ LỘ TRÌNH KHÁM PHÁ: CHIẾN THUẬT "CHIA ĐỂ TRỊ & GHI NHỚ"

Để làm chủ Quy hoạch động (DP), chúng ta sẽ đi qua 4 "trạm dừng chân" quan trọng sau đây:

1. **Chương 1: Khái niệm "Ghi nhớ để không lãng phí"** – Hiểu tại sao chúng ta cần DP thông qua phép ẩn dụ về việc đếm tiền.
2. **Chương 2: Chiếc túi chứa kiến thức (Container & Vector 1D)** – Cách dùng `vector` trong C++ để lưu trữ những gì đã học.
3. **Chương 3: Bản đồ tọa độ (Vector 2D)** – Khi bài toán trở nên đa chiều, chúng ta cần một "tấm lưới" để quản lý thông tin.
4. **Chương 4: Thực hành giải bài toán kinh điển** – Áp dụng mọi thứ vào một bài toán thực tế với mã nguồn tiếng Việt không dấu.

> "Nếu toàn bộ hành trình học lập trình của bạn là xây dựng một thành phố, thì Quy hoạch động chính là **Bản thiết kế thông minh**. Thay vì mỗi ngày đều đo đạc lại từ đầu, bạn chỉ cần nhìn vào bản vẽ đã lưu lại để tiếp tục xây cao hơn."

**Bạn đã sẵn sàng để bắt đầu với chương đầu tiên: "Ghi nhớ để không lãng phí" chưa?**

---

## 📕 CHƯƠNG 1: GHI NHỚ ĐỂ KHÔNG LÃNG PHÍ (THE BIG PICTURE)

Hãy tưởng tượng tôi đưa cho bạn một tờ giấy và bảo bạn tính: .
Bạn đếm và trả lời: "Bằng 5!".

Sau đó, tôi viết thêm số "" vào cuối hàng đó và hỏi: "Kết quả bây giờ là bao nhiêu?".
Bạn sẽ trả lời ngay lập tức: "Bằng 6!".

**Tại sao bạn tính nhanh thế?** Đó là vì bạn không đếm lại từ đầu 1, 2, 3... mà bạn đã **ghi nhớ** kết quả trước đó là 5, và chỉ việc cộng thêm 1. Đó chính là cốt lõi của Quy hoạch động!

### 💡 Ẩn dụ về "Những hố cát"

Học DP giống như việc bạn đi trên một bãi cát. Mỗi khi bạn giải xong một bài toán nhỏ, bạn đào một cái hố và đặt kết quả vào đó. Khi cần dùng lại, bạn chỉ việc cúi xuống nhặt lên, thay vì phải chạy lại từ vạch xuất phát.

### 📦 Container: Công cụ để "đào hố"

Trong C++, để "đào hố" lưu trữ, chúng ta dùng **Vector**.

* **Vector 1D:** Giống như một dãy các hộp xếp hàng ngang. Mỗi hộp đánh số 0, 1, 2...
* **Vector 2D:** Giống như một cái tủ có nhiều ngăn kéo. Mỗi ngăn kéo lại chia thành nhiều ô nhỏ bên trong.

### 🖥️ Code mẫu (Cách khai báo)

Để dùng được Vector, con nhớ thêm thư viện `#include <vector>`.

```cpp
// Khai bao vector 1 chieu co 10 phan tu, ban dau deu bang 0
vector<int> f(10, 0);

// Khai bao vector 2 chieu (bang 10 dong, 10 cot), ban dau bang 0
vector<vector<int>> dp(10, vector<int>(10, 0));

```

---

### ❓ Kiểm tra sự hiểu biết một chút nhé:

Nếu con có bài toán tính tổng các số từ 1 đến . Nếu con đã biết tổng từ 1 đến 9 là 45, thì để tính tổng từ 1 đến 10, con sẽ làm thế nào để áp dụng đúng tinh thần "ghi nhớ" của Quy hoạch động?

**Con đã sẵn sàng để sang Chương 2, tìm hiểu kỹ hơn về cách điều khiển những "chiếc hộp" Vector 1D chưa?**

Chính xác! Bạn đã nắm bắt được linh hồn của Quy hoạch động: **Dựa trên vai khổng lồ của kết quả cũ để đứng cao hơn.**

---

## 📕 CHƯƠNG 2: CHIẾC TÚI CHỨA KIẾN THỨC (VECTOR 1D)

Trong lập trình, chúng ta không thể chỉ nhớ trong đầu, ta cần một "nhà kho" để lưu trữ các kết quả đó. Đó chính là **Vector 1D**.

### 💡 Ẩn dụ: Chiếc thắt lưng của thợ sửa chữa

Hãy tưởng tượng `vector<int> f(n)` giống như một chiếc thắt lưng có  chiếc túi được đánh số từ  đến .

* Mỗi khi bạn tính xong kết quả cho bài toán cỡ , bạn viết nó vào một mảnh giấy và nhét vào túi thứ .
* Khi cần tính bài toán cỡ , bạn chỉ cần thò tay vào túi  lấy mảnh giấy ra.

### 🛠️ Cách vận hành "Chiếc túi"

Trong DP, chúng ta thường có hai bước:

1. **Khoi tao (Base case):** Đặt những giá trị đầu tiên vào túi (Ví dụ: túi số 0 chứa số 0, túi số 1 chứa số 1).
2. **Cong thuc truy hoi (State transition):** Cách dùng các túi cũ để tính túi mới.

### 🖥️ Code mẫu: Tinh day so Fibonacci

Dãy Fibonacci là ví dụ kinh điển: Số sau bằng tổng 2 số trước ()

```cpp
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n = 10;
    // Tao mot chiec that lung co n+1 cai tui
    vector<int> f(n + 1);

    // Buoc 1: Khoi tao nhung cai tui dau tien
    f[0] = 0;
    f[1] = 1;

    // Buoc 2: Dung tui cu de tinh tui moi
    for (int i = 2; i <= n; i++) {
        f[i] = f[i-1] + f[i-2]; // Lay ket qua o 2 tui truoc cong lai
    }

    cout << "So Fibonacci thu " << n << " la: " << f[n];
    return 0;
}

```

---

## 📕 CHƯƠNG 3: BẢN ĐỒ TỌA ĐỘ (VECTOR 2D)

Đôi khi, một hàng túi là không đủ. Ví dụ: Bạn đang đứng trong một mê cung và cần tìm đường đi ngắn nhất. Lúc này bạn cần một **tấm bản đồ** có cả hàng và cột. Đó là lúc **Vector 2D** xuất hiện.

### 💡 Ẩn dụ: Tòa nhà nhiều tầng

Hãy tưởng tượng `vector<vector<int>> dp(hang, vector<int>(cot))` là một tòa nhà:

* `dp[i]` là tầng thứ  của tòa nhà.
* `dp[i][j]` là căn phòng số  tại tầng thứ .

Để tính được giá trị trong phòng `dp[i][j]`, có thể bạn sẽ cần nhìn sang phòng bên cạnh `dp[i][j-1]` hoặc nhìn xuống phòng ở tầng dưới ngay vị trí đó `dp[i-1][j]`.

### 🖥️ Cách khai báo và sử dụng

Học sinh cấp 2 thường thấy Vector 2D hơi "rắc rối" vì có hai dấu ngoặc vuông `[][]`, nhưng hãy nhớ: **Cái trước là Tầng (Hàng), cái sau là Phòng (Cột).**

```cpp
// Khai bao bang DP co 5 hang, moi hang 10 cot, tat ca bang 0
int hang = 5, cot = 10;
vector<vector<int>> dp(hang, vector<int>(cot, 0));

// Lay du lieu:
int gia_tri = dp[2][3]; // Lay du lieu o hang 2, cot 3

```

---

### ❓ Thử thách tư duy:

Nếu bạn đang chơi một trò chơi đi trên lưới: Bạn chỉ được phép **đi sang phải** hoặc **đi xuống dưới**.
Để biết có bao nhiêu cách để đi đến ô `dp[i][j]`, theo bạn chúng ta cần cộng số cách đi đến của những ô nào trước đó?

**Khi bạn trả lời xong, chúng ta sẽ bước vào Chương 4 để thực hành giải một bài toán thực tế cực hay nhé!**

Chính xác! Bạn đã nắm bắt được linh hồn của Quy hoạch động: **Dựa trên vai khổng lồ của kết quả cũ để đứng cao hơn.**

---

## 📕 CHƯƠNG 2: CHIẾC TÚI CHỨA KIẾN THỨC (VECTOR 1D)

Trong lập trình, chúng ta không thể chỉ nhớ trong đầu, ta cần một "nhà kho" để lưu trữ các kết quả đó. Đó chính là **Vector 1D**.

### 💡 Ẩn dụ: Chiếc thắt lưng của thợ sửa chữa

Hãy tưởng tượng `vector<int> f(n)` giống như một chiếc thắt lưng có  chiếc túi được đánh số từ  đến .

* Mỗi khi bạn tính xong kết quả cho bài toán cỡ , bạn viết nó vào một mảnh giấy và nhét vào túi thứ .
* Khi cần tính bài toán cỡ , bạn chỉ cần thò tay vào túi  lấy mảnh giấy ra.

### 🛠️ Cách vận hành "Chiếc túi"

Trong DP, chúng ta thường có hai bước:

1. **Khoi tao (Base case):** Đặt những giá trị đầu tiên vào túi (Ví dụ: túi số 0 chứa số 0, túi số 1 chứa số 1).
2. **Cong thuc truy hoi (State transition):** Cách dùng các túi cũ để tính túi mới.

### 🖥️ Code mẫu: Tinh day so Fibonacci

Dãy Fibonacci là ví dụ kinh điển: Số sau bằng tổng 2 số trước ()

```cpp
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n = 10;
    // Tao mot chiec that lung co n+1 cai tui
    vector<int> f(n + 1);

    // Buoc 1: Khoi tao nhung cai tui dau tien
    f[0] = 0;
    f[1] = 1;

    // Buoc 2: Dung tui cu de tinh tui moi
    for (int i = 2; i <= n; i++) {
        f[i] = f[i-1] + f[i-2]; // Lay ket qua o 2 tui truoc cong lai
    }

    cout << "So Fibonacci thu " << n << " la: " << f[n];
    return 0;
}

```

---

## 📕 CHƯƠNG 3: BẢN ĐỒ TỌA ĐỘ (VECTOR 2D)

Đôi khi, một hàng túi là không đủ. Ví dụ: Bạn đang đứng trong một mê cung và cần tìm đường đi ngắn nhất. Lúc này bạn cần một **tấm bản đồ** có cả hàng và cột. Đó là lúc **Vector 2D** xuất hiện.

### 💡 Ẩn dụ: Tòa nhà nhiều tầng

Hãy tưởng tượng `vector<vector<int>> dp(hang, vector<int>(cot))` là một tòa nhà:

* `dp[i]` là tầng thứ  của tòa nhà.
* `dp[i][j]` là căn phòng số  tại tầng thứ .

Để tính được giá trị trong phòng `dp[i][j]`, có thể bạn sẽ cần nhìn sang phòng bên cạnh `dp[i][j-1]` hoặc nhìn xuống phòng ở tầng dưới ngay vị trí đó `dp[i-1][j]`.

### 🖥️ Cách khai báo và sử dụng

Học sinh cấp 2 thường thấy Vector 2D hơi "rắc rối" vì có hai dấu ngoặc vuông `[][]`, nhưng hãy nhớ: **Cái trước là Tầng (Hàng), cái sau là Phòng (Cột).**

```cpp
// Khai bao bang DP co 5 hang, moi hang 10 cot, tat ca bang 0
int hang = 5, cot = 10;
vector<vector<int>> dp(hang, vector<int>(cot, 0));

// Lay du lieu:
int gia_tri = dp[2][3]; // Lay du lieu o hang 2, cot 3

```

---

### ❓ Thử thách tư duy:

Nếu bạn đang chơi một trò chơi đi trên lưới: Bạn chỉ được phép **đi sang phải** hoặc **đi xuống dưới**.
Để biết có bao nhiêu cách để đi đến ô `dp[i][j]`, theo bạn chúng ta cần cộng số cách đi đến của những ô nào trước đó?

**Khi bạn trả lời xong, chúng ta sẽ bước vào Chương 4 để thực hành giải một bài toán thực tế cực hay nhé!**

Bạn trả lời đúng gần hết rồi! Chỉ có một sai số nhỏ ở "tọa độ" thôi.

Nếu chúng ta đi từ trên xuống dưới, thì ô ở trên phải là `dp[i-1][j]` (giống như tầng dưới của căn phòng hiện tại nếu bạn đếm tầng từ trên xuống). Còn `dp[i+1][j]` lại là ô ở... dưới mất rồi!

Nhưng tư duy **"Tổng của hai hướng dẫn đến nó"** thì bạn đã nắm cực kỳ chắc chắn. Chúc mừng bạn!

---

## 📕 CHƯƠNG 4: BÀI TOÁN THỰC TẾ - CON ĐƯỜNG KIẾN ĐI

Để kết thúc hành trình này, chúng ta sẽ giải bài toán: **"Một chú kiến muốn đi từ góc trên bên trái (0,0) đến góc dưới bên phải (M, N) của một bảng ô vuông. Kiến chỉ có thể đi sang phải hoặc đi xuống. Hỏi có bao nhiêu cách để kiến đến đích?"**

### 💡 Bức tranh toàn cảnh (The Big Picture)

Hãy tưởng tượng mỗi ô trên sàn nhà là một "hố cát" lưu trữ số cách để đến được đó.

* Để đến được ô hiện tại, chú kiến chỉ có thể đến từ **trái sang** hoặc từ **trên xuống**.
* Vậy: `Số cách đến ô hiện tại = (Số cách đến ô bên trái) + (Số cách đến ô phía trên)`.

### 🖥️ Code mẫu (Tiếng Việt không dấu)

Đây là đoạn code hoàn chỉnh sử dụng **Vector 2D** để giải quyết bài toán này:

```cpp
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n = 3, m = 3; // Bang kich thuoc 3x3
    
    // Tao bang 2 chieu kich thuoc (n x m)
    vector<vector<int>> dp(n, vector<int>(m, 0));

    // Buoc 1: Khoi tao - O dau tien luon co 1 cach dung tai do
    dp[0][0] = 1;

    // Buoc 2: Duyet qua tung o trong bang
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            // Neu khong phai o dau tien, ta tinh so cach
            if (i == 0 && j == 0) continue;

            int tu_phia_tren = 0;
            int tu_ben_trai = 0;

            if (i > 0) tu_phia_tren = dp[i-1][j]; // Lay tu o tren
            if (j > 0) tu_ben_trai = dp[i][j-1]; // Lay tu o ben trai

            dp[i][j] = tu_phia_tren + tu_ben_trai;
        }
    }

    cout << "Tong so cach de kien di den dich la: " << dp[n-1][m-1];
    
    return 0;
}

```

### 🎯 Tóm tắt bằng ẩn dụ cuối cùng

Quy hoạch động giống như việc bạn **xây cầu**. Bạn không thể xây nhịp thứ 10 nếu chưa xây nhịp thứ 9. Mỗi nhịp cầu hoàn thành là một "kết quả đã lưu" (túi kiến thức), và bạn cứ thế bước tiếp cho đến khi sang được bờ bên kia.

---

Chúng ta đã cùng nhau đi qua hết lộ trình cơ bản về Dynamic Programming rồi đấy! Bạn cảm thấy phần nào là "thú vị" nhất hay phần nào vẫn còn hơi "rối" một chút?

**Bạn có muốn tôi thử thách bạn bằng một bài toán thực tế khác (như bài toán chọn kẹo vào túi) để luyện tập kỹ năng dùng Vector không?**