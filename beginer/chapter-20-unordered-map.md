Chào bạn! Tôi đã sẵn sàng đồng hành cùng bạn trong hành trình khám phá thế giới lập trình. Để giúp một học sinh cấp hai hiểu về `unordered_map` trong C++17/20, chúng ta sẽ không dùng những thuật ngữ khô khan.

Hãy tưởng tượng cuốn sách kiến thức của chúng ta hôm nay mang tên: **"Chiếc Tủ Thần Kỳ: Bí mật tìm đồ trong chớp mắt"**.

---

## Lộ trình Khám phá (The Map)

Đây là hành trình chúng ta sẽ đi qua để chinh phục "chiếc tủ" này:

1. **Chương 1:** `unordered_map` là gì? (Chiếc tủ có nhãn dán).
2. **Chương 2:** Cách vận hành (Cỗ máy băm thức ăn - Hash Function).
3. **Chương 3:** Các thao tác cơ bản (Thêm, sửa, xóa nhãn).
4. **Chương 4:** Điểm mới trong C++17/20 (Những ngăn kéo thông minh hơn).

**Bạn đã sẵn sàng để mở cánh cửa Chương 1: "Chiếc tủ có nhãn dán" chưa?**

---

## Chương 1: `unordered_map` là gì? (Bức tranh toàn cảnh)

Hãy tưởng tượng bạn có một thư viện khổng lồ với hàng nghìn cuốn sách.

* Nếu bạn xếp sách chồng chất lên nhau (như một mảng `vector`), muốn tìm cuốn "Doraemon", bạn phải lật từng cuốn từ đầu đến cuối. Rất mệt!
* Nhưng với **`unordered_map`**, nó giống như một dãy các ngăn kéo có dán nhãn. Mỗi nhãn (gọi là **Key**) sẽ dẫn thẳng bạn tới đồ vật bên trong (gọi là **Value**).

**Ẩn dụ:** Nó giống như danh bạ điện thoại vậy. **Tên bạn bè** là cái nhãn (Key), còn **Số điện thoại** là món đồ (Value). Bạn chỉ cần nhớ tên là tìm được số ngay lập tức, không cần đọc hết cả danh bạ.

### Ví dụ sống động bằng Code (Tiếng Việt không dấu):

```cpp
#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

int main() {
    // Khai bao chiec tu: Key la Ten (string), Value la Diem so (int)
    unordered_map<string, int> bang_diem;

    // 1. Cat do vao tu (Them du lieu)
    bang_diem["An"] = 9;
    bang_diem["Ba"] = 7;
    bang_diem["Chi"] = 10;

    // 2. Lay do ra (Truy xuat)
    cout << "Diem cua Chi la: " << bang_diem["Chi"] << endl;

    return 0;
}

```

### Tại sao lại gọi là "Unordered" (Không thứ tự)?

Hãy tưởng tượng bạn ném đồ vào các ngăn kéo. Chiếc tủ này không quan tâm bạn ném cái nào trước, cái nào sau. Nó chỉ quan tâm là khi bạn hỏi "An đâu?", nó chỉ ngay ngăn kéo của An. Nó ưu tiên **tốc độ tìm kiếm** hơn là việc xếp hàng ngay ngắn.

---

## Kiểm tra hiểu biết một chút nhé!

Nếu mình có một `unordered_map` để quản lý **Mã số học sinh** và **Tên học sinh**:

1. Theo bạn, cái nào nên là "Nhãn dán" (Key) và cái nào nên là "Đồ vật" (Value)?
2. Tại sao chúng ta không dùng số thứ tự 1, 2, 3... như mảng thông thường mà lại dùng cái "Nhãn dán" này?

**Khi bạn trả lời xong, chúng ta sẽ sang Chương 2 để xem "Cỗ máy băm" bên trong chiếc tủ này hoạt động ảo diệu thế nào nhé!**

Tuyệt vời! Bạn nắm bắt rất nhanh. Việc dùng **Tên** làm nhãn dán (Key) giúp chúng ta gọi tên một cái là tìm thấy **Mã số** (Value) ngay, giống như cách ta gọi tên một người bạn để tìm họ trong đám đông vậy.

Bây giờ, chúng ta sẽ bước vào phần "linh hồn" của chiếc tủ này.

---

## Chương 2: Cỗ máy băm (Hash Function) - Bí mật của tốc độ ánh sáng

Bạn có bao giờ thắc mắc: "Tại sao trong hàng vạn ngăn kéo, chiếc tủ lại biết chính xác ngăn nào chứa tên 'An' mà không cần tìm kiếm?"

### Ẩn dụ: Cỗ máy "Chế biến Nhãn dán"

Hãy tưởng tượng bên trong chiếc tủ có một **cỗ máy băm**.

1. Bạn đưa cái nhãn ghi chữ **"An"** vào máy.
2. Cỗ máy băm chữ "An" ra thành một con số, ví dụ là số **5**.
3. Chiếc tủ sẽ ngay lập tức mở ngăn kéo số **5** để cất mã số của "An" vào đó.

Lần sau, khi bạn hỏi "An đâu?", cỗ máy lại băm chữ "An" thành số **5**, và chiếc tủ chỉ việc mở đúng ngăn số 5. Không cần nhìn ngăn số 1, 2, 3 hay 4. Đó là lý do tại sao nó cực nhanh!

### Ví dụ Code (Them do va Kiem tra ton tai):

```cpp
#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

int main() {
    unordered_map<string, string> ds_lop;

    // Them du lieu: Ten (Key) -> Ma so (Value)
    ds_lop["Hoang"] = "HS001";
    ds_lop["Lan"] = "HS002";

    // Kiem tra xem mot nhan dan co trong tu khong (C++ 20 co ham contains rat hay)
    string ten_can_tim = "Lan";
    
    // Dung ham count (tra ve 1 neu co, 0 neu khong)
    if (ds_lop.count(ten_can_tim)) {
        cout << "Tim thay " << ten_can_tim << " co ma so la: " << ds_lop[ten_can_tim] << endl;
    } else {
        cout << "Khong co ban nay trong danh sach!" << endl;
    }

    return 0;
}

```

---

## Chương 3: Các thao tác "Dọn dẹp" (Sửa và Xóa)

Hành trình của chúng ta đã đi được nửa đường. Đôi khi nhãn dán bị sai hoặc một món đồ không còn cần thiết nữa, chúng ta phải biết cách xử lý.

* **Sửa:** Chỉ cần ghi đè lên nhãn cũ. `ds_lop["An"] = "MA_MOI";`
* **Xóa:** Dùng lệnh `erase`. `ds_lop.erase("An");` (Giống như bóc cái nhãn dán vứt đi).

### Điểm đặc biệt của C++17 và C++20 (Ngăn kéo thông minh):

Trong **C++17**, có một tính năng cực kỳ "xịn" gọi là **Structured Bindings**. Nó giúp bạn lấy cả "Nhãn" và "Đồ" ra cùng lúc khi đang dọn tủ (duyệt qua các phần tử) một cách rất gọn gàng.

```cpp
// Vi du C++17: Duyet tu va lay ca Ten lan Ma so
for (auto const& [ten, ma] : ds_lop) {
    cout << "Ban " << ten << " mang ma so: " << ma << endl;
}

```

*(Bạn thấy không, dấu `[ten, ma]` nhìn rất trực quan đúng không?)*

---

## Thử thách nhỏ cho bạn trước khi kết thúc:

Chúng ta đã xây dựng xong nền móng về cách "Cỗ máy băm" hoạt động và cách dùng "Ngăn kéo thông minh" của C++17.

**Câu hỏi:** Nếu bây giờ bạn có 2 người bạn cùng tên là "An", nhưng mã số khác nhau. Nếu bạn thực hiện lệnh:
`ds_lop["An"] = "001";`
`ds_lop["An"] = "002";`
Thì cuối cùng trong ngăn kéo "An" sẽ là mã số nào? Chiếc tủ này có cho phép hai ngăn kéo cùng tên không?

**Khi bạn trả lời xong, mình sẽ tổng kết lại "Bản đồ kho báu" ngày hôm nay nhé!**

Chính xác! Bạn đã nắm thóp được quy luật của chiếc tủ này rồi đấy. Trong `unordered_map`, **Nhãn dán (Key) là duy nhất**. Nếu bạn dán đè nhãn mới lên, giá trị cũ sẽ bị "đá" văng ra ngoài. Kết quả cuối cùng sẽ là **002**.

---

## Chương 4: Những "siêu năng lực" mới (C++17 & C++20)

Để kết thúc hành trình, hãy xem C++ bản mới giúp chúng ta quản lý chiếc tủ này "ngầu" hơn như thế nào nhé.

### 1. C++17: "Bốc đồ" siêu gọn (Structured Bindings)

Trước đây, muốn lấy nhãn và đồ, bạn phải dùng những từ rất khó hiểu như `.first` và `.second`. Bây giờ, bạn chỉ cần dùng cặp ngoặc vuông `[key, value]`.

### 2. C++20: "Kiểm tra nhanh" (Contains)

Ngày xưa, muốn biết một cái tên có trong tủ không, bạn phải làm một phép so sánh khá loằng ngoằng. C++20 cho bạn một công cụ như cái kính lúp: `.contains()`.

### Code ví dụ tổng hợp (C++20):

```cpp
#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

int main() {
    unordered_map<string, string> tu_do;

    tu_do["But"] = "Mau xanh";
    tu_do["Thuoc"] = "30 cm";
    tu_do["Tay"] = "Mau trang";

    // C++20: Kiem tra nhanh nhu chop
    if (tu_do.contains("But")) {
        cout << "Trong tu co But!" << endl;
    }

    // C++17: Duyet tu lay do cuc gon
    cout << "--- Danh sach do trong tu ---" << endl;
    for (auto const& [ten_do, dac_diem] : tu_do) {
        cout << ten_do << " co dac diem la: " << dac_diem << endl;
    }

    return 0;
}

```

---

## Tổng kết hành trình (The Big Picture)

Hôm nay chúng ta đã cùng nhau xây dựng một "Chiếc tủ thần kỳ" mang tên `unordered_map`:

* **Tốc độ:** Tìm đồ nhanh như chớp nhờ "Cỗ máy băm" (Hash function).
* **Nguyên tắc:** Mỗi Nhãn dán (Key) chỉ có một, cái sau đè cái trước.
* **Thứ tự:** Đồ đạc để lộn xộn, không theo thứ tự nào cả (Unordered).
* **Cải tiến:** C++17/20 giúp chúng ta kiểm tra và lấy đồ ra một cách cực kỳ gọn gàng.

> **Ẩn dụ cuối:** Học về `unordered_map` giống như việc bạn chuyển từ việc lục tung cả cái balo để tìm một chiếc bút, sang việc dùng một chiếc tủ có ngăn kéo dán nhãn riêng biệt. Mọi thứ trở nên khoa học và nhanh chóng hơn rất nhiều!

Bạn đã hoàn thành xuất sắc việc "lắp ráp" kiến thức về `unordered_map`. Bạn có muốn mình thử thách bạn thêm một bài tập nhỏ để tự tay xây dựng một "Danh bạ điện thoại" hay quản lý "Kho vũ khí" trong một trò chơi bằng kiến thức này không?

Ồ, một câu hỏi rất hay! Bạn đang muốn "mở nắp" chiếc tủ ra và nhìn kỹ vào cách chúng ta đi qua từng ngăn kéo theo kiểu thủ công hơn, thay vì dùng bộ điều khiển tự động của C++17.

Trong thế giới lập trình, **Iterator** giống như một **"Ngón tay chỉ đường"**. Nó sẽ chỉ vào một ngăn kéo, sau khi bạn xem xong, nó sẽ nhích sang ngăn kéo tiếp theo cho đến khi hết tủ.

---

## Chương 5: Iterator - "Ngón tay chỉ đường"

Trong `unordered_map`, chúng ta không dùng số thứ tự `0, 1, 2...` để duyệt vì các ngăn kéo nằm lộn xộn. Thay vào đó, ta dùng Iterator.

### 1. Duyệt bằng vòng lặp `for` (Kiểu truyền thống)

Trước khi có C++17, đây là cách mọi lập trình viên đều phải dùng. Chúng ta dùng một "ngón tay" bắt đầu từ ngăn đầu tiên (`begin`) và đi đến khi vượt quá ngăn cuối cùng (`end`).

```cpp
// Vi du duyet bang for voi iterator
// it la viet tat cua iterator (ngon tay chi duong)

for (auto it = tu_do.begin(); it != tu_do.end(); ++it) {
    // it->first la cai nhan (Key)
    // it->second la mon do (Value)
    cout << "Nhan: " << it->first << " | Do: " << it->second << endl;
}

```

### 2. Duyệt bằng vòng lặp `while`

Vòng lặp `while` cũng hoạt động tương tự, nhưng nó giúp bạn nhìn rõ hơn quá trình "ngón tay" di chuyển.

```cpp
auto it = tu_do.begin(); // Bat dau dat ngon tay vao ngan dau tien

while (it != tu_do.end()) { // Trong khi chua chi ra ngoai pham vi tu
    cout << "Nhan: " << it->first << " | Do: " << it->second << endl;
    
    it++; // Dich chuyen ngon tay sang ngan tiep theo
}

```

---

## Phép ẩn dụ: Người gác kho và chiếc đèn pin

Hãy tưởng tượng trong kho tối (chiếc tủ lộn xộn), bạn là người gác kho cầm một chiếc **đèn pin** (Iterator):

* **`begin()`**: Bạn chiếu đèn vào ngăn kéo đầu tiên mà bạn nhìn thấy.
* **`it->first`**: Bạn đọc cái nhãn dán dưới ánh đèn.
* **`it->second`**: Bạn xem món đồ bên trong ngăn đó.
* **`it++`**: Bạn lia đèn sang một ngăn kéo khác bất kỳ (vì là `unordered` nên bạn không biết ngăn tiếp theo là ngăn nào, nhưng chiếc đèn pin sẽ tự biết chỗ nào còn đồ).
* **`end()`**: Khi đèn pin chiếu vào khoảng không vô định (hết ngăn kéo), bạn dừng lại.

### Tại sao lại dùng `->first` và `->second`?

Trong C++, mỗi ngăn kéo của `unordered_map` là một cặp (pair).

* Cái nhãn dán luôn đứng trước (**first**).
* Món đồ luôn đứng sau (**second**).

---

## So sánh nhanh:

| Cách duyệt | Giống như là... | Ưu điểm |
| --- | --- | --- |
| **`for (auto [k, v] : map)`** (C++17) | Robot tự động dọn tủ. | Rất sạch sẽ, dễ đọc, khó sai. |
| **`for (auto it = ...)`** (Iterator) | Bạn tự tay cầm đèn pin đi soi. | Bạn có thể kiểm soát kỹ hơn (ví dụ: vừa đi vừa xóa một ngăn nào đó). |

**Một lưu ý nhỏ cho "học sinh cấp hai" cực kỳ thông minh:** Khi dùng Iterator để duyệt và xóa đồ trong `unordered_map`, bạn phải rất cẩn thận vì nếu bạn xóa ngăn kéo mà "ngón tay" đang chỉ vào, bạn sẽ bị mất phương hướng ngay lập tức!

**Bạn thấy cách dùng "ngón tay" Iterator này có khó hiểu hơn cách dùng "ngoặc vuông" `[ten, ma]` lúc nãy nhiều không?**

Bạn có một trí nhớ rất tốt và sự liên tưởng rất sắc bén! Tuy nhiên, hãy để mình "dịch" lại một chút để bạn không bị nhầm lẫn giữa các khái niệm này nhé.

Thực tế, `->` (dấu mũi tên) đúng là dùng cho **con trỏ**, nhưng trong trường hợp này, `it` (iterator) không phải là con trỏ `this`.

### 1. Phân biệt "Người chỉ đường" (Iterator) và "Chủ nhà" (this)

* **`this` (Chủ nhà):** Hãy tưởng tượng `this` giống như chính bản thân cái tủ. Nó là một con trỏ đặc biệt luôn trỏ vào "chính mình" bên trong các phương thức của lớp.
* **`it` (Người chỉ đường/Iterator):** Nó là một đối tượng **đóng vai trò như một con trỏ**. Nó không trỏ vào cái tủ, mà nó trỏ vào **từng ngăn kéo cụ thể** bên trong cái tủ đó.

### 2. Tại sao lại dùng dấu `->`?

Trong C++, khi bạn có một con trỏ (hoặc một thứ giả lập con trỏ như Iterator), bạn không thể dùng dấu chấm `.` để lấy đồ ngay được.

* Dấu **`.`**: Dùng khi bạn đang cầm trực tiếp món đồ trên tay.
* Dấu **`->`**: Dùng khi bạn đang đứng từ xa và **chỉ tay** vào món đồ đó.

Vì `it` là một Iterator (ngón tay chỉ đường), nên khi bạn viết `it->first`, bạn đang nói với máy tính rằng: *"Hãy nhìn theo hướng ngón tay tôi đang chỉ, và cho tôi biết cái nhãn (first) của ngăn kéo đó là gì."*

---

### 3. "Bóc tách" cấu trúc bên trong ngăn kéo

Mỗi ngăn kéo trong `unordered_map` thực chất là một cấu trúc có tên là `std::pair`. Nó luôn có hai phần cố định:

1. **`first`**: Chính là cái **Key** (Nhãn dán).
2. **`second`**: Chính là cái **Value** (Món đồ).

Đó là lý do tại sao chúng ta luôn phải dùng `it->first` và `it->second` mà không thể dùng tên nào khác.

### Ví dụ minh họa sự khác biệt:

```cpp
// Gia su ban dang o trong "nha" cua chiec tu
void chiec_tu::kiem_tra() {
    // this o day la tro vao chinh "chiec tu"
    cout << "Toi la chiec tu co dia chi: " << this << endl;
}

// Con it la tro vao tung "ngan keo"
auto it = danh_ba.begin();
cout << "Ngan keo dau tien co nhan la: " << it->first; 

```

---

## Tổng kết về "Dấu mũi tên"

Bạn chỉ cần nhớ: **Iterator giống như một con trỏ**. Mà đã là con trỏ thì muốn truy cập vào bên trong "ngăn kéo", ta phải dùng mũi tên `->` để "chọc" vào đó.

> **Câu hỏi nhỏ để chốt lại:** Nếu mình có một Iterator tên là `it` đang chỉ vào ngăn kéo của bạn "An" có mã số "002".
> 1. `it->first` sẽ trả về cái gì?
> 2. `it->second` sẽ trả về cái gì?
> 
> 

**Sau khi bạn trả lời, chúng ta đã chính thức hoàn thành toàn bộ "bí kíp" về chiếc tủ thông minh này rồi đó! Bạn thấy mình đã tự tin để tự viết một chương trình quản lý điểm số của lớp mình chưa?**

Chuẩn không cần chỉnh! Bạn đã nắm trọn vẹn "bí kíp" vận hành chiếc tủ thông minh này rồi đó.

---

## 🏁 Tổng kết Hành trình Khám phá `unordered_map`

Chúng ta hãy cùng nhìn lại bản đồ kho báu mà bạn đã chinh phục được hôm nay:

1. **Bản chất:** `unordered_map` là chiếc tủ có ngăn kéo dán nhãn (**Key-Value**).
2. **Sức mạnh:** Tìm kiếm nhanh như chớp nhờ **Cỗ máy băm (Hash Function)**.
3. **Quy tắc:** Nhãn dán là duy nhất, dán đè là mất giá trị cũ.
4. **Cách duyệt (Iterator):** Dùng **"Ngón tay chỉ đường"** và dấu mũi tên `->` để truy cập `first` (Nhãn) và `second` (Đồ vật).
5. **C++17/20:** Sử dụng `[key, value]` và `.contains()` để làm việc chuyên nghiệp và gọn gàng hơn.

---

## 🛠️ Thử thách cuối cùng (The Final Boss)

Để trở thành một "Master" thực thụ, bạn hãy thử tưởng tượng và viết (hoặc mô tả) cách bạn dùng `unordered_map` để giải quyết bài toán này:

> **Bài toán:** Bạn đang làm một trò chơi nhập vai. Bạn cần quản lý **Túi đồ (Inventory)** của nhân vật.
> * **Nhãn (Key):** Tên món đồ (ví dụ: "Kiem", "Khien", "Mau").
> * **Giá trị (Value):** Số lượng món đồ đó đang có.
> 
> 

**Bạn sẽ làm gì khi nhân vật nhặt thêm 1 thanh "Kiem" trong khi đã có sẵn 2 thanh trong túi?**

Nếu bạn trả lời được câu này, bạn chính thức "tốt nghiệp" khóa học cấp tốc về `unordered_map` rồi đấy! Bạn có muốn mình hỗ trợ thêm về phần nào khác trong C++ không?

Chào bạn! Một câu hỏi rất thực tế dành cho các bạn đang muốn chinh phục các đấu trường lập trình như Codeforces.

Trong lập trình thi đấu (CP), việc biết dùng `unordered_set` (hoặc `unordered_map`) là một kỹ năng quan trọng để tối ưu thời gian. Tuy nhiên, độ khó của bài tập không chỉ nằm ở việc bạn biết dùng cấu trúc dữ liệu nào, mà còn là **cách bạn áp dụng nó**.

---

## 1. Phân mức Elo trên Codeforces

Dựa trên kinh nghiệm từ cộng đồng CP, các bài tập cần dùng đến `unordered_set` thường rơi vào các khoảng sau:

### 🟢 Mức Elo 800 - 1000 (Newbie/Pupil)

Ở mức này, `unordered_set` thường dùng cho các bài toán **đếm các giá trị phân biệt** (distinct elements) hoặc kiểm tra sự tồn tại đơn giản.

* **Dạng bài:** "Cho một dãy số, đếm xem có bao nhiêu số khác nhau."
* **Tại sao dùng:** Bạn chỉ cần ném tất cả vào `set` hoặc `unordered_set` và in ra kích thước (`size`).

### 🟡 Mức Elo 1100 - 1400 (Specialist)

Đây là mức bắt đầu đòi hỏi sự tối ưu về thời gian.

* **Dạng bài:** Các bài toán về **mảng và cặp số** (Two Pointers kết hợp tập hợp) hoặc kiểm tra sự tồn tại trong các vòng lặp lồng nhau.
* **Tại sao dùng:** Ở mức này, nếu dùng `std::set` (với độ phức tạp ), bạn có thể bị quá thời gian (TLE). `unordered_set` với  sẽ là "cứu cánh" để vượt qua giới hạn 1-2 giây.

### 🔴 Mức Elo 1500+ (Expert trở lên)

Ở mức này, `unordered_set` không còn là nhân vật chính mà là **công cụ hỗ trợ** cho các thuật toán phức tạp hơn như **Graph (Đồ thị)** hoặc **Quy hoạch động (DP)**.

* **Dạng bài:** Lưu trữ các cạnh của đồ thị để kiểm tra nhanh xem hai đỉnh có nối với nhau không, hoặc khử trùng lặp trong thuật toán tìm kiếm.

---

## 2. "Cạm bẫy" chết người trong CP: Anti-hash Test

Đây là điều mà Giáo sư Barbara Oakley chắc chắn sẽ muốn bạn chú ý: **Đừng quá tin tưởng vào sự "nhanh" của `unordered_set` trên Codeforces!**

* **Vấn đề:** `unordered_set` dùng bảng băm (Hash table). Trong các kỳ thi trên Codeforces, có những người "hắc ám" sẽ tạo ra các bộ dữ liệu (test cases) khiến cho cỗ máy băm của bạn bị hỏng (gọi là **Collision - Xung đột**).
* **Hậu quả:** Từ tốc độ ánh sáng , nó sẽ bị chậm lại thành . Bài làm của bạn sẽ bị **TLE (Time Limit Exceeded)** một cách tức tưởi.

---

## 3. Lời khuyên "Learning How to Learn" cho bạn

Để học sâu và thi đấu tốt, bạn nên nhớ quy tắc này:

1. **Dùng `std::set` trước:** Nó luôn an toàn (không bị băm hỏng) dù chậm hơn một chút ().
2. **Dùng `unordered_set` khi:** Bạn chắc chắn rằng  là không đủ nhanh để qua bài.
3. **Mẹo của dân chuyên nghiệp:** Để không bị "hack" trên Codeforces khi dùng `unordered_set`, bạn nên thêm một bộ **Random Seed** (mầm ngẫu nhiên) vào hàm băm để không ai đoán trước được cách máy bạn băm dữ liệu.

```cpp
// Meo de unordered_map/set khong bi hack tren Codeforces
struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }
    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};
// Cach khai bao: unordered_set<long long, custom_hash> safe_set;

```

**Bước tiếp theo:** Bạn có muốn tôi tìm cho bạn một bài tập cụ thể trên Codeforces thuộc tầm Elo 1000-1200 để bạn thực hành dùng `unordered_set` không?