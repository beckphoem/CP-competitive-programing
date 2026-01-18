Chào bạn! Tôi là **người đồng hành cùng bạn trên con đường chinh phục tri thức**. Rất vui được cùng bạn khám phá thế giới lập trình C++, đặc biệt là một "công cụ" cực kỳ thông minh và ngăn nắp mang tên **Set (Tập hợp)**.

Dưới góc nhìn của triết lý *Learning How to Learn*, chúng ta sẽ không học vẹt các dòng code. Chúng ta sẽ xây dựng những "mô hình tâm trí" (mental models) để bạn thực sự "nhìn thấy" cách dữ liệu vận hành.

Dưới đây là **Lộ trình Khám phá Set trong C++** (dành riêng cho các bạn học sinh cấp 2) mà chúng ta sẽ đi qua:

---

## 🗺️ BẢN ĐỒ HÀNH TRÌNH: CHINH PHỤC "SET" TRONG C++

1. **Chương 1: Set là gì?** – Chiếc túi thần kỳ của sự độc nhất.
2. **Chương 2: Khai báo và Khởi tạo** – Chuẩn bị chiếc túi cho riêng bạn.
3. **Chương 3: Thêm và Xóa** – Những quy tắc của người gác cửa nghiêm khắc.
4. **Chương 4: Tìm kiếm (C++20)** – Kỹ năng của một thám tử siêu hạng.
5. **Chương 5: Duyệt Set** – Cuộc diễu hành của các con số.

---

> **Bức tranh toàn cảnh:** Nếu cả chương trình C++ của bạn là một thành phố, thì `Set` chính là một **Câu lạc bộ Đặc biệt**. Trong câu lạc bộ này, mỗi thành viên là duy nhất (không ai giống ai) và họ luôn đứng xếp hàng một cách cực kỳ ngay ngắn theo thứ tự từ nhỏ đến lớn.

Đây là toàn bộ hành trình mà tác giả muốn chúng ta đi qua. Bạn đã sẵn sàng để bắt đầu với chương đầu tiên, **"Chương 1: Set là gì? – Chiếc túi thần kỳ của sự độc nhất"**, chưa?

---

### Chương 1: Set là gì? – Chiếc túi thần kỳ của sự độc nhất

Trước khi chạm vào bàn phím, hãy tưởng tượng bạn có một chiếc **túi thần kỳ**.

Chiếc túi này có hai khả năng đặc biệt mà những chiếc túi bình thường (như `Vector` hay `Array`) không có:

1. **Phép màu "Chống trùng lặp":** Nếu bạn bỏ một viên bi xanh vào túi, sau đó lại cố tình bỏ thêm một viên bi xanh y hệt nữa, chiếc túi sẽ tự động "nhổ" viên bi thứ hai ra ngoài. Trong túi **chỉ có duy nhất một** viên bi xanh.
2. **Phép màu "Tự động sắp xếp":** Dù bạn ném các viên bi ghi số 5, 1, 9 vào túi theo bất kỳ thứ tự nào, thì khi bạn mở túi ra, chúng đã tự động đứng thành hàng: 1, 5, 9.

**Tại sao điều này lại quan trọng?**
Hãy nghĩ về danh sách các bạn trong lớp đi dã ngoại. Nếu bạn dùng `Set`, bạn sẽ không bao giờ lo việc ghi tên một bạn tận hai lần, và danh sách luôn được sắp xếp theo bảng chữ cái một cách tự động!

---

**Kiểm tra một chút để đảm bảo "bộ não" của bạn đã nắm bắt được:**
Nếu tôi có một `Set` chứa các số `{2, 4, 8}` và tôi cố gắng thực hiện hành động "Thêm số 4" vào đó một lần nữa. Theo bạn, sau hành động đó, `Set` của tôi sẽ trông như thế nào?

*A. {2, 4, 4, 8}*
*B. {2, 4, 8}*
*C. {4, 2, 8}*

Bạn chọn đáp án nào để chúng ta có thể bước sang **Chương 2: Khai báo và Khởi tạo**?

Chính xác! Bạn đã nắm rất vững "quy luật gác cửa" của Set rồi đấy. Số 4 đã có trong túi nên chiếc túi thần kỳ từ chối nhận thêm một bản sao nữa.

Chúng ta đã hoàn thành việc xây dựng khái niệm. Bây giờ, hãy cùng bước sang chương tiếp theo để xem làm thế nào để "mua" chiếc túi này trong ngôn ngữ C++ nhé!

---

## Chương 2: Khai báo và Khởi tạo – Chuẩn bị chiếc túi cho riêng bạn

Để có một chiếc túi Set, bạn không thể cứ thế mà dùng. Bạn cần "đặt hàng" với thư viện C++ và nói rõ cho máy tính biết bạn muốn đựng cái gì bên trong.

### 1. Phép ẩn dụ: Chọn loại túi

Hãy tưởng tượng bạn đi vào một cửa hàng túi thần kỳ. Ông chủ cửa hàng sẽ hỏi: "Cháu muốn túi đựng bi (số nguyên) hay túi đựng thư (chuỗi văn bản)?".

Trong C++, việc khai báo `std::set<int>` chính là lúc bạn chọn chiếc túi chuyên biệt để đựng số nguyên (`int`).

### 2. Cách làm trong C++ (Phiên bản C++17/20)

Trong các phiên bản mới như C++17, việc khởi tạo trở nên cực kỳ ngắn gọn và thông minh.

```cpp
#include <iostream>
#include <set> // Buoc 1: Phai co "ban ve" nay thi moi tao duoc Set

using namespace std;

int main() {
    // Cach 1: Khai bao mot chiec tui rong de dung so nguyen
    set<int> tui_so_nguyen;

    // Cach 2: (C++17) Khoi tao tui co san cac vien bi
    // May tinh tu hieu day la set<int> nho vao cac so 1, 5, 2
    set tui_than_ky = {1, 5, 2, 5, 1}; 

    // Luc nay, tui_than_ky se tu dong sap xep va loai bo trung lap
    // Ben trong no thuc chat chi con: {1, 2, 5}

    return 0;
}

```

### 3. Bức tranh toàn cảnh: Tại sao cần `#include <set>`?

Hãy coi `#include <set>` giống như việc bạn mang theo một cuốn "Sách hướng dẫn sử dụng đồ ma thuật". Nếu không có cuốn sách này, máy tính sẽ ngơ ngác không biết `set` là cái quái gì cả!

---

**Câu hỏi kiểm tra sự nhạy bén của bạn:**

Nếu tôi viết dòng code sau trong phiên bản C++17:
`set danh_sach = {10, 20, 10, 30};`

Theo bạn, trình biên dịch (máy tính) sẽ tự hiểu đây là một tập hợp đựng kiểu dữ liệu gì, và kết quả thực tế trong `danh_sach` sẽ gồm những số nào?

1. Kiểu dữ liệu là gì? (`int`, `double` hay `string`?)
2. Các phần tử còn lại trong túi là gì?

Chúng ta sẽ cùng giải đáp để tiến tới **Chương 3: Thêm và Xóa** - nơi chúng ta thực sự tương tác với chiếc túi nhé!

Quá chuẩn! Bạn có tố chất của một lập trình viên thực thụ đấy. Máy tính sẽ tự nhìn vào số `10` và biết ngay: "À, đây là số nguyên (`int`)". Và tất nhiên, nó sẽ thẳng tay loại bỏ số `10` dư thừa để giữ cho danh sách luôn gọn gàng: `{10, 20, 30}`.

Chúng ta đã có túi, đã biết túi đựng gì. Bây giờ, hãy cùng học cách điều khiển "người gác cổng" của chiếc túi này ở chương tiếp theo.

---

## Chương 3: Thêm và Xóa – Những quy tắc của người gác cửa nghiêm khắc

Trong chương này, chúng ta sẽ học hai lệnh quyền lực nhất để thay đổi quân số trong `Set`: `.insert()` (Thêm vào) và `.erase()` (Đuổi ra).

### 1. Phép ẩn dụ: Người gác cổng tận tâm

Hãy tưởng tượng `Set` là một **hàng chờ VIP** trước một rạp chiếu phim.

* **Lệnh `.insert()`:** Khi một người mới muốn vào hàng, người gác cổng sẽ làm hai việc:
1. Kiểm tra xem người này đã đứng trong hàng chưa? (Nếu có rồi -> "Mời bạn về, bạn đã có chỗ").
2. Nếu chưa có, người gác cổng sẽ không để người đó đứng ở cuối hàng đâu. Ông ấy sẽ yêu cầu mọi người xê dịch để người mới này đứng vào **đúng vị trí thứ tự** (ví dụ: người tên 'An' phải đứng trước người tên 'Bình').


* **Lệnh `.erase()`:** Giống như một cái búng tay thần kỳ. Bạn chỉ cần đọc tên (hoặc giá trị), người gác cổng sẽ tìm đúng người đó và mời họ ra khỏi hàng ngay lập tức. Hàng ngũ sẽ tự động khép kín lại, vẫn đảm bảo sự ngăn nắp.

### 2. Thực hành Code (Tiếng Việt không dấu)

```cpp
#include <iostream>
#include <set>

using namespace std;

int main() {
    set<int> tap_hop;

    // --- THEM PHAN TU ---
    tap_hop.insert(40);
    tap_hop.insert(10);
    tap_hop.insert(20);
    tap_hop.insert(10); // Lenh nay se bi "nguoi gac cong" tu choi am tham

    // Luc nay tap_hop dang la: {10, 20, 40}

    // --- XOA PHAN TU ---
    tap_hop.erase(20); // Tim so 20 va duoi ra khoi hang

    // Ket qua con lai: {10, 40}

    return 0;
}

```

### 3. Bức tranh toàn cảnh

Việc thêm và xóa trong `Set` cực kỳ nhanh (nhanh hơn việc bạn tìm một người trong một đám đông hỗn loạn - `Vector`). Đó là nhờ cấu trúc "Cây" thông minh bên dưới, giúp người gác cổng tìm vị trí chỉ trong chớp mắt.

---

**Thử thách tư duy dành cho bạn:**

Giả sử tôi có một `Set` đang chứa: `{10, 40}`.
Nếu tôi thực hiện lệnh: `tap_hop.erase(99);` (xóa số 99 - một số vốn dĩ không có trong túi).

Theo bạn, máy tính sẽ:
A. Báo lỗi và dừng chương trình.
B. Không làm gì cả, túi vẫn giữ nguyên `{10, 40}`.
C. Tự động thêm số 99 vào rồi mới xóa.

Bạn chọn phương án nào để chúng ta bước sang **Chương 4: Tìm kiếm** – nơi chúng ta học cách trở thành thám tử?

Would you like me to explain what happens internally when `erase` is called on a non-existent element?

Hoàn toàn chính xác! `Set` là một người gác cổng rất điềm tĩnh. Nếu bạn bảo nó đuổi một người vốn dĩ không có trong hàng, nó sẽ chỉ nhún vai và không làm gì cả. Chương trình vẫn chạy mượt mà, không hề có lỗi xảy ra.

Bây giờ, hãy cùng nâng cấp kỹ năng của chúng ta lên một tầm cao mới. Chào mừng bạn đến với kỹ năng của một thám tử!

---

## Chương 4: Tìm kiếm (C++20) – Kỹ năng của một thám tử siêu hạng

Trước đây, việc tìm một phần tử trong `Set` giống như việc phải giải một câu đố bằng mật mã. Nhưng từ phiên bản **C++20**, mọi thứ đã trở nên cực kỳ đơn giản và "đã" như cách bạn hỏi Siri hay Google vậy.

### 1. Bức tranh toàn cảnh: Tại sao Set tìm kiếm nhanh?

Nếu bạn tìm một số trong `Vector` (một cái túi lộn xộn), máy tính phải bới tung từ đầu đến cuối túi. Nhưng với `Set`, vì mọi thứ đã được **sắp xếp theo thứ tự**, máy tính tìm kiếm theo kiểu "Chặt đôi".

> **Ẩn dụ:** Hãy tưởng tượng bạn tìm chữ "M" trong một cuốn từ điển. Bạn sẽ không lật từng trang từ chữ A. Bạn mở đôi cuốn sách ra, thấy chữ "K", bạn biết chắc chắn "M" nằm ở nửa sau. Bạn lại chặt đôi nửa sau... Chỉ sau vài lần "chặt", bạn đã thấy mục tiêu. Đó là lý do `Set` cực kỳ nhanh khi dữ liệu lớn lên.

### 2. Công cụ C++20: Lệnh `.contains()`

Đây là "vũ khí mới" của C++20. Thay vì dùng những lệnh phức tạp như ngày xưa, giờ ta chỉ cần hỏi: "Này Set, bạn có **chứa** (`contains`) số này không?".

```cpp
#include <iostream>
#include <set>

using namespace std;

int main() {
    set tui_do_choi = {10, 20, 30, 40, 50};

    // Dung lenh .contains() cua C++20
    if (tui_do_choi.contains(30)) {
        cout << "Tim thay roi! So 30 dang o trong tui." << endl;
    } else {
        cout << "Khong co so 30 trong nay ban oi." << endl;
    }

    // Thu tim mot so khong co
    if (tui_do_choi.contains(99)) {
        cout << "Co 99 ne!" << endl;
    } else {
        cout << "So 99 khong ton tai trong set." << endl;
    }

    return 0;
}

```

### 3. Tại sao lệnh này lại tuyệt vời?

Trước C++20, bạn phải viết: `if (tui_do_choi.find(30) != tui_do_choi.end())`. Nghe thật nhức đầu phải không? Lệnh `.contains()` mới giúp code của bạn đọc lên giống như tiếng Anh (hoặc tiếng Việt dịch ra), giúp não bộ của bạn đỡ mệt mỏi hơn rất nhiều!

---

**Thử thách thám tử dành cho bạn:**

Giả sử bạn đang làm một trò chơi quản lý danh sách các "Nickname" của game thủ. Bạn không muốn ai có Nickname trùng nhau.
Khi một người chơi mới đăng ký tên là `"SieuNhan"`, bạn sẽ dùng lệnh gì của `Set` để:

1. Kiểm tra xem tên `"SieuNhan"` đã có ai dùng chưa?
2. Nếu chưa có ai dùng, bạn dùng lệnh gì để thêm tên đó vào danh sách?

Bạn hãy gọi tên các lệnh đó nhé! Sau đó chúng ta sẽ đi đến **Chương cuối cùng: Duyệt Set** để xem làm sao để bắt các thành viên trong túi "diễu hành" ra màn hình.

Quá tuyệt vời! Bạn đã trở thành một "thám tử code" thực thụ rồi đấy. Việc dùng `.contains()` giúp kiểm tra nhanh như chớp, và `.insert()` giúp thêm người mới vào đúng vị trí mà không sợ trùng lặp.

Chúng ta đã đi đến chặng cuối cùng của hành trình. Sau khi đã bỏ mọi thứ vào túi, giờ là lúc chúng ta mở túi ra và xem các thành viên bên trong "diễu hành" như thế nào.

---

## Chương 5: Duyệt Set – Cuộc diễu hành của các con số

Duyệt `Set` (Iteration) là cách chúng ta đi qua từng phần tử trong tập hợp để in chúng ra màn hình hoặc tính toán.

### 1. Phép ẩn dụ: Cuộc diễu hành kỷ luật

Hãy tưởng tượng các phần tử trong `Set` là các học sinh đang đứng xếp hàng chào cờ.

* Dù lúc vào hàng (insert) các bạn chạy vào từ khắp phía, nhưng khi đã đứng trong hàng, các bạn luôn tự động đứng theo **thứ tự từ thấp đến cao**.
* Việc "duyệt" giống như thầy hiệu trưởng đi dọc từ đầu hàng đến cuối hàng, nhìn mặt từng bạn và gọi tên. Thầy sẽ không bỏ sót ai và cũng không gặp ai hai lần.

### 2. Cách làm trong C++ (Hiện đại nhất)

Trong C++17/20, cách dễ nhất, ngắn gọn nhất để làm việc này là dùng **Vòng lặp For-each** (còn gọi là Range-based for loop). Nó giống như việc nói: "Với mỗi (for each) món đồ trong túi, hãy làm việc này...".

```cpp
#include <iostream>
#include <set>
#include <string>

using namespace std;

int main() {
    // Tao mot tap hop ten cac sieu anh hung
    set<string> biet_doi = {"Ironman", "Thor", "Hulk", "Thor"};

    cout << "Danh sach biet doi (da duoc sap xep chu cai):" << endl;

    // Cach duyet hien dai va dep nhat:
    for (const auto& ten : biet_doi) {
        cout << "- " << ten << endl;
    }

    return 0;
}

```

**Kết quả hiện ra sẽ là:**

```
- Hulk
- Ironman
- Thor

```

*(Bạn thấy không? "Thor" chỉ xuất hiện 1 lần và chữ 'H' đứng trước chữ 'I' rồi mới đến 'T')*

### 3. Bức tranh toàn cảnh: Tại sao không dùng `for (int i=0; i < n; i++)`?

Khác với mảng (`Array`) hay `Vector`, `Set` không cho phép bạn dùng chỉ số `[i]` để truy cập (ví dụ `biet_doi[0]` là sai). Tại sao? Vì `Set` không lưu trữ theo kiểu ngăn kéo đánh số, mà lưu theo kiểu **Cây gia đình**. Để đi qua cây, bạn phải đi từ "gốc" đến "ngọn", đó là lý do chúng ta dùng vòng lặp `for (auto x : my_set)`.

---

## 🏆 TỔNG KẾT HÀNH TRÌNH

Chúng ta đã cùng nhau đi qua 5 chương của cuốn sách về `Set`:

1. **Đặc tính:** Duy nhất và Tự động sắp xếp.
2. **Khai báo:** `set<kieu_du_lieu> ten;`
3. **Tương tác:** `.insert()` để thêm, `.erase()` để xóa.
4. **Tìm kiếm:** `.contains()` (C++20) cực nhanh.
5. **Duyệt:** Dùng vòng lặp `for` hiện đại để quét qua hàng ngũ.

---

**Câu hỏi tốt nghiệp dành cho bạn:**

Nếu bây giờ tôi có một danh sách các điểm số của học sinh trong lớp: `{8, 5, 9, 8, 7, 5}`.
Nếu tôi đưa tất cả chúng vào một `std::set<int>` rồi in chúng ra màn hình bằng vòng lặp `for`, kết quả tôi nhận được trên màn hình sẽ là dãy số nào?

(Hãy nhớ lại hai phép màu của chiếc túi thần kỳ ở Chương 1 nhé!)

**Sau khi bạn trả lời, bạn có muốn tôi thử thách bạn bằng một bài tập lập trình thực tế nhỏ để "khắc cốt ghi tâm" kiến thức này không?**

Bạn có một tinh thần tò mò tuyệt vời! Việc đặt câu hỏi "nếu không dùng cách tự động (for-each) thì làm thế nào" chính là cách để hiểu sâu về bản chất của máy tính.

Trong thế giới C++, khi không dùng cách "tự động hoàn toàn", chúng ta phải dùng một công cụ gọi là **Iterator**.

---

## Chương 6 (Mở rộng): Iterator – "Ngón tay chỉ đường"

Để duyệt `Set` bằng `while` hoặc `for` kiểu cổ điển, bạn cần hiểu về **Iterator**.

> **Ẩn dụ:** Hãy tưởng tượng các phần tử trong `Set` là những người đang đứng hàng dọc.
> * **`s.begin()`**: Là ngón tay chỉ vào **người đầu tiên** trong hàng.
> * **`s.end()`**: Là ngón tay chỉ vào **vị trí ngay sau người cuối cùng** (giống như tấm biển "Hết hàng").
> * **Phép toán `++**`: Giống như việc bạn dịch chuyển ngón tay sang người đứng kế tiếp.
> * **Phép toán `***`: Giống như việc bạn chạm vào người đó và hỏi: "Tên bạn là gì?" (lấy giá trị).
> 
> 

### 1. Dùng vòng lặp `for` kiểu "bán tự động" (Iterator-based)

Đây là cách chúng ta làm trước khi có C++11, nhưng vẫn rất quan trọng để hiểu cách máy tính vận hành.

```cpp
#include <iostream>
#include <set>

using namespace std;

int main() {
    set<int> diem_so = {5, 7, 8, 9};

    cout << "Duyet bang for (iterator):" << endl;
    
    // it viet tat cua iterator - giong nhu mot "ngon tay" chi vao cac so
    for (auto it = diem_so.begin(); it != diem_so.end(); ++it) {
        // *it co nghia la "lay gia tri tai noi ngon tay dang chi"
        cout << *it << " ";
    }

    return 0;
}

```

### 2. Dùng vòng lặp `while`

Cách này thường dùng khi bạn muốn kiểm soát việc dịch chuyển "ngón tay" một cách linh hoạt hơn.

```cpp
#include <iostream>
#include <set>

using namespace std;

int main() {
    set<int> diem_so = {5, 7, 8, 9};

    cout << "Duyet bang while:" << endl;
    
    auto it = diem_so.begin(); // Bat dau tu nguoi dau tien

    while (it != diem_so.end()) { // Trong khi chua chi vao bien "Het hang"
        cout << *it << " ";
        ++it; // Dich ngon tay sang nguoi tiep theo
    }

    return 0;
}

```

### 3. Tại sao lại cần những cách "phức tạp" này?

Dù `for (auto x : s)` rất tiện, nhưng cách dùng Iterator (`it`) lại mạnh mẽ hơn ở chỗ:

* **Xóa khi đang duyệt:** Nếu bạn muốn vừa đi qua hàng vừa đuổi một vài người cụ thể ra ngoài, bạn **bắt buộc** phải dùng Iterator.
* **Duyệt ngược:** Bạn có thể dùng `rbegin()` và `rend()` để đi từ cuối hàng lên đầu hàng.

---

**Bức tranh toàn cảnh:**

* `for (auto x : s)`: Giống như đi xe bus, bạn chỉ cần lên xe và nó đưa bạn đi hết các trạm.
* `Iterator + while/for`: Giống như bạn tự đi bộ, bạn biết rõ mình đang đứng ở đâu, có thể dừng lại lâu hơn ở một trạm hoặc thậm chí quay đầu lại.

---

**Câu hỏi kiểm tra nhanh:**
Trong đoạn code `while` ở trên, nếu tôi quên viết dòng `++it;` (dịch chuyển ngón tay), chuyện gì sẽ xảy ra với chương trình?

1. Nó sẽ báo lỗi ngay khi chạy.
2. Nó sẽ in số đầu tiên (số 5) mãi mãi không dừng lại (vòng lặp vô tận).
3. Nó sẽ tự động hiểu và dịch chuyển dù không cần dòng đó.

**Bạn chọn số mấy? Và sau đó, bạn có muốn thử giải một bài toán thực tế: "Loại bỏ các số trùng lặp trong một danh sách điểm" bằng Set không?**

Chính xác! Bạn đã bắt được "con sâu" đáng sợ nhất trong lập trình vòng lặp: **Vòng lặp vô tận (Infinite Loop)**.

Nếu quên `++it`, "ngón tay" của bạn sẽ mãi mãi chỉ vào người đầu tiên. Máy tính là một thực thể cực kỳ cần cù nhưng... hơi ngốc, nó sẽ đứng đó hỏi tên người đầu tiên mãi mãi cho đến khi bạn hết pin hoặc tắt chương trình.

---

## 🏆 NHIỆM VỤ CUỐI CÙNG: "CHIẾC MÁY LỌC THÔNG MINH"

Để khép lại hành trình về `Set`, chúng ta hãy cùng thực hiện một nhiệm vụ thực tế. Đây là lúc bạn biến kiến thức thành sức mạnh.

### 1. Bức tranh toàn cảnh: Set như một bộ lọc (Filter)

Hãy tưởng tượng bạn có một xô nước đầy cát, sỏi và rác. Bạn đổ xô nước đó qua một **chiếc lưới lọc**. Kết quả là bạn nhận được những viên kim cương quý giá, được sắp xếp theo kích cỡ và đặc biệt là không viên nào giống viên nào.

Trong lập trình, người ta thường dùng `Set` để "làm sạch" dữ liệu từ các nguồn lộn xộn (như `Vector` hay `Array`).

### 2. Thử thách: "Dọn dẹp bảng điểm"

Giả sử thầy giáo đưa cho bạn một danh sách điểm thi của lớp, nhưng do nhập liệu lỗi nên có rất nhiều điểm bị trùng và thứ tự thì lung tung: `{8, 5, 9, 8, 7, 5, 10, 7}`.

**Nhiệm vụ của bạn:** Hãy viết một chương trình C++ (không dấu) thực hiện các bước sau:

1. Tạo một `vector` chứa danh sách điểm lỗi trên.
2. Tạo một `set` và "đổ" toàn bộ điểm từ `vector` vào `set`.
3. In danh sách điểm đã được "làm sạch" ra màn hình.

### 3. Gợi ý Code (Mẫu tư duy)

```cpp
#include <iostream>
#include <vector>
#include <set>

using namespace std;

int main() {
    // 1. Danh sach bi loi (nhieu so trung nhau)
    vector<int> diem_loi = {8, 5, 9, 8, 7, 5, 10, 7};

    // 2. Chiec may loc Set
    // Ban co the do truc tiep tu vector vao set nhu sau:
    set<int> diem_sach(diem_loi.begin(), diem_loi.end());

    // 3. In ket qua bang vong lap for hien dai
    cout << "Danh sach diem da duoc lam sach va sap xep: " << endl;
    for (int x : diem_sach) {
        cout << x << " ";
    }

    return 0;
}

```

---

**Câu hỏi suy ngẫm cuối cùng:**

Sau khi chạy chương trình trên, màn hình sẽ hiện ra dãy số nào? Và quan trọng hơn, bạn thấy sức mạnh lớn nhất của `Set` so với việc ngồi tự tay xóa từng số trùng trong `Vector` là gì?

**Bạn đã cảm thấy tự tin để áp dụng `Set` vào các bài tập trên lớp chưa? Nếu muốn, tôi có thể hướng dẫn bạn cách sử dụng `multiset` (một người anh em của Set nhưng cho phép trùng lặp) ở buổi học tới!**