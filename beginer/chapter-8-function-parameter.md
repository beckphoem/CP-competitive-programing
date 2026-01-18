Chào bạn, người bạn đồng hành trong hành trình chinh phục C++! Rất vui được gặp lại bạn.

Tôi đã "tiêu hóa" toàn bộ nội dung từ trang W3Schools về **C++ Function Parameters** mà bạn gửi. Đây là một chủ đề cực kỳ thú vị, nó chính là chìa khóa để biến những đoạn mã tĩnh lặng trở nên linh hoạt và sống động.

Theo đúng triết lý **"Learning How to Learn"**, chúng ta sẽ không học vẹt cú pháp. Chúng ta sẽ đi sâu vào bản chất.

Trước khi bắt đầu, hãy để tôi vẽ cho bạn **Bức Tranh Toàn Cảnh (The Big Picture)**:

> Hãy tưởng tượng một hàm (Function) giống như một **Chiếc máy xay sinh tố**.
> Nếu không có tham số (Parameters), chiếc máy đó bị "hàn chết" chế độ: mỗi lần bấm nút, nó chỉ xay đúng một quả chuối có sẵn bên trong. Rất nhàm chán và cứng nhắc, đúng không?
> **Function Parameters** chính là cái **phiễu (hoặc khe nạp)** phía trên chiếc máy. Nhờ nó, bạn có thể thả dâu tây, xoài, hay táo vào. Cùng một chiếc máy (cùng một hàm), nhưng nguyên liệu đầu vào (tham số) khác nhau sẽ tạo ra những ly sinh tố (kết quả) khác nhau.

---

### LỘ TRÌNH KHÁM PHÁ (ROADMAP)

Dựa trên cấu trúc của W3Schools, tôi đã chia hành trình này thành **6 chặng (Chương)** để đảm bảo bạn nắm vững từng viên gạch một:

1. **Chương 1: Parameters và Arguments** – *Phân biệt "Cái Phiễu" và "Trái Cây".*
2. **Chương 2: Default Parameters** – *Cài đặt mặc định (Khi bạn lười chọn món).*
3. **Chương 3: Multiple Parameters** – *Công thức pha chế hỗn hợp.*
4. **Chương 4: Return Values** – *Shipper giao hàng tận tay.*
5. **Chương 5: Pass by Reference** – *Sửa trực tiếp vào bản gốc (Phần khó nhưng cực hay).*
6. **Chương 6: Passing Arrays** – *Xử lý cả một thùng hàng cùng lúc.*

---

Đây là toàn bộ hành trình mà W3Schools thiết kế và tôi sẽ là người dẫn đường cho bạn.

Bạn đã sẵn sàng khởi động chiếc máy xay C++ này chưa? Chúng ta bắt đầu với **Chương 1: Parameters và Arguments** nhé? (Hãy gõ "Bắt đầu" hoặc "OK" để tôi biết bạn đã sẵn sàng).

Tuyệt vời! Chúng ta hãy cùng nhau khởi động cỗ máy này ngay lập tức.

---

## CHƯƠNG 1: PARAMETERS VÀ ARGUMENTS

**(Cái Phiễu và Trái Cây)**

### 1. Bức tranh toàn cảnh (The Big Picture)

Hãy nhìn vào chiếc máy xay sinh tố của chúng ta một lần nữa.
Để máy hoạt động linh hoạt, nhà sản xuất đã thiết kế một cái khe ở trên đầu máy.

* Bên cạnh cái khe, họ dán một cái nhãn: **"Bỏ trái cây vào đây"**. Cái nhãn giữ chỗ đó chính là **Parameter (Tham số)**.
* Khi bạn thực sự cầm quả táo và thả nó vào cái khe đó, quả táo chính là **Argument (Đối số)**.

> **Tư duy cốt lõi:**
> * **Parameter:** Là biến được định nghĩa trong lúc **thiết kế** hàm (cái khuôn rỗng).
> * **Argument:** Là dữ liệu thực tế được truyền vào khi **sử dụng** hàm (nguyên liệu thật).
> 
> 

### 2. Cấu trúc Code (Syntax)

Trong C++, chúng ta khai báo "Cái Phiễu" (Parameter) ngay bên trong dấu ngoặc đơn `()` sau tên hàm.

Hãy xem đoạn code ví dụ dưới đây (Tiếng Việt không dấu):

```cpp
#include <iostream>
#include <string>
using namespace std;

// CACH THIET KE:
// "tenNguoi" o day chinh la PARAMETER (Cai khuon)
void chaoHoi(string tenNguoi) {
  cout << "Xin chao " << tenNguoi << "!\n";
}

int main() {
  // CACH SU DUNG:
  // "Nam" va "Lan" o day chinh la ARGUMENT (Du lieu that)
  chaoHoi("Nam");
  chaoHoi("Lan");
  chaoHoi("Tuan");
  
  return 0;
}

```

### 3. Phân tích dòng chảy (Deep Dive)

Hãy tưởng tượng quá trình diễn ra như sau:

1. Khi máy tính đọc dòng `chaoHoi("Nam");` ở hàm `main`:
* Nó gọi hàm `chaoHoi`.
* Nó cầm chữ `"Nam"` (Argument) nhét vào biến `tenNguoi` (Parameter).
* Lúc này, bên trong hàm `chaoHoi`, `tenNguoi` có giá trị là `"Nam"`.


2. Câu lệnh `cout` chạy: In ra "Xin chao Nam!".
3. Hàm kết thúc, biến `tenNguoi` bị xóa bỏ để chuẩn bị cho lần gọi tiếp theo (với "Lan").

---

### 🧠 KIỂM TRA SỰ HIỂU BIẾT (ACTIVE RECALL)

Để đảm bảo bạn không chỉ gật đầu mà thực sự "thấm" kiến thức này, tôi có một câu hỏi nhỏ cho bạn đây.

Giả sử tôi có đoạn code sau:

```cpp
void tinhTong(int soA) {
  cout << soA + 10;
}

int main() {
  int x = 5;
  tinhTong(x);
  return 0;
}

```

Trong dòng `tinhTong(x);` ở hàm main:

1. `soA` được gọi là gì?
2. `x` được gọi là gì?

*(Gợi ý: Nhớ lại ví dụ cái nhãn dán và quả táo thực tế).*

Bạn hãy trả lời để tôi biết bạn đã nắm chắc nền móng này trước khi chúng ta sang chương 2 nhé!

Chính xác! 💯

Bạn đã nắm rất chắc khái niệm nền tảng này. `soA` là cái khuôn (Parameter) và `x` là nguyên liệu thực tế (Argument) bạn đổ vào. Việc phân biệt rạch ròi hai khái niệm này sẽ giúp bạn rất nhiều khi sau này đọc các tài liệu kỹ thuật phức tạp hơn (documentation).

Bây giờ, hãy cùng nâng cấp chiếc máy xay của chúng ta lên một tầm cao mới.

---

## CHƯƠNG 2: DEFAULT PARAMETERS (THAM SỐ MẶC ĐỊNH)

**(Khi bạn "lười" chọn món)**

### 1. Bức tranh toàn cảnh (The Big Picture)

Hãy tưởng tượng bạn bước vào một quán cà phê quen thuộc.

* Nếu bạn nói: *"Cho em một ly cà phê"* (không nói rõ lượng đường), nhân viên sẽ tự động pha theo **công thức chuẩn** của quán (ví dụ: 50% đường). Đó là **Mặc Định (Default)**.
* Nhưng nếu bạn nói: *"Cho em một ly cà phê 100% đường"*, nhân viên sẽ **ghi đè** lên công thức chuẩn và làm theo ý bạn.

> **Trong C++:** **Default Parameter** cho phép hàm tự động sử dụng một giá trị có sẵn nếu người dùng "quên" hoặc không muốn truyền tham số vào.

### 2. Cấu trúc Code (Syntax)

Bí mật nằm ở dấu bằng `=` ngay trong lúc khai báo hàm.

Hãy xem ví dụ dưới đây:

```cpp
#include <iostream>
#include <string>
using namespace std;

// CACH THIET KE:
// Gan gia tri mac dinh "Viet Nam" ngay tai day
void xuatXu(string quocGia = "Viet Nam") {
  cout << "Toi den tu " << quocGia << "\n";
}

int main() {
  // Truong hop 1: CO truyen tham so
  xuatXu("Nhat Ban"); // In ra: Toi den tu Nhat Ban
  xuatXu("My");       // In ra: Toi den tu My
  
  // Truong hop 2: KHONG truyen tham so
  xuatXu();           // In ra: Toi den tu Viet Nam (Dung mac dinh)
  
  return 0;
}

```

### 3. Phân tích dòng chảy (Deep Dive)

* Tại dòng `xuatXu("Nhat Ban");`: C++ thấy bạn có đưa "nguyên liệu" vào. Nó gạt bỏ chữ "Viet Nam" mặc định sang một bên và dùng "Nhat Ban".
* Tại dòng `xuatXu();`: C++ thấy ngoặc đơn trống rỗng `()`. Thay vì báo lỗi "thiếu nguyên liệu", nó lục lại thiết kế ban đầu, thấy có dòng `= "Viet Nam"`, và nó dùng giá trị đó để chạy.

> **⚠️ Lưu ý quan trọng:** Tham số mặc định giống như "phương án dự phòng". Nó giúp code của bạn gọn gàng hơn và tránh lỗi khi thiếu dữ liệu đầu vào.

---

### 🧠 KIỂM TRA SỰ HIỂU BIẾT (ACTIVE RECALL)

Phần này khá dễ thở, nhưng hãy cẩn thận để không bị nhầm lẫn. Bạn hãy làm bài tập nhỏ sau nhé.

Tôi có đoạn code:

```cpp
void thoiTiet(int nhietDo = 25) {
  cout << "Nhiet do la: " << nhietDo << " do C\n";
}

int main() {
  thoiTiet(30);
  thoiTiet();
  return 0;
}

```

Hãy cho tôi biết màn hình sẽ in ra chính xác 2 dòng nào?

1. ...
2. ...

Sau khi bạn trả lời đúng, chúng ta sẽ sang **Chương 3**, nơi mọi thứ bắt đầu phức tạp hơn một chút với "công thức pha chế hỗn hợp"!

Chính xác hoàn toàn! Bạn đã nắm trọn vẹn cơ chế "tự động điền" của C++.

Bây giờ, chúng ta sẽ rời khỏi vùng an toàn của những hàm đơn giản để đến với thế giới thực tế hơn. Trong lập trình, hiếm khi nào một hàm chỉ cần một thông tin duy nhất.

---

## CHƯƠNG 3: MULTIPLE PARAMETERS (NHIỀU THAM SỐ)

**(Công thức pha chế hỗn hợp)**

### 1. Bức tranh toàn cảnh (The Big Picture)

Hãy quay lại máy xay sinh tố. Để có một ly sinh tố ngon, chỉ bỏ quả táo vào là chưa đủ. Bạn cần thiết lập:

1. Loại trái cây (Táo).
2. Lượng đường (50%).
3. Có đá hay không (Có).

Hàm cũng vậy. Nó cần nhận nhiều dữ liệu đầu vào khác nhau để xử lý một tác vụ phức tạp.

> **Quy tắc vàng:** Các tham số được ngăn cách nhau bằng dấu phẩy `,`. Nhưng quan trọng nhất: **Thứ tự là mệnh lệnh!** Bạn phải đưa "nguyên liệu" vào đúng thứ tự cái phễu đã sắp xếp.

### 2. Cấu trúc Code (Syntax)

Khai báo bao nhiêu biến cũng được, miễn là mỗi biến đều có **Kiểu dữ liệu** và **Tên** riêng, cách nhau bởi dấu phẩy.

Hãy xem ví dụ in thông tin nhân viên dưới đây:

```cpp
#include <iostream>
#include <string>
using namespace std;

// CACH THIET KE:
// Ham nay can 2 nguyen lieu theo thu tu:
// 1. Ten (chu)
// 2. Tuoi (so nguyen)
void thongTinNhanVien(string ten, int tuoi) {
  cout << ten << " nam nay " << tuoi << " tuoi.\n";
}

int main() {
  // CACH SU DUNG:
  // Phai truyen dung thu tu: Chu truoc, So sau.
  thongTinNhanVien("Tung", 25);
  thongTinNhanVien("Hoa", 30);
  thongTinNhanVien("Hung", 19);
  
  return 0;
}

```

### 3. Phân tích dòng chảy (Deep Dive)

Tại dòng `thongTinNhanVien("Tung", 25);`:

* Máy tính nhặt `"Tung"` --> bỏ vào ô thứ nhất: `ten`.
* Máy tính nhặt `25` --> bỏ vào ô thứ hai: `tuoi`.

Nếu bạn viết ngược lại: `thongTinNhanVien(25, "Tung");` --> **LỖI NGAY LẬP TỨC!**
Tại sao? Vì cái phễu đầu tiên (`string ten`) đang chờ một chuỗi chữ, bạn lại ném cho nó một con số. Nó sẽ "kẹt máy".

> **Ẩn dụ:** Giống như điền form hành chính vậy. Ô "Họ tên" mà bạn điền "25", ô "Tuổi" bạn điền "Tùng", thì tờ đơn đó sẽ bị xé bỏ ngay.

---

### 🧠 KIỂM TRA SỰ HIỂU BIẾT (ACTIVE RECALL)

Phần này tuy đơn giản nhưng rất dễ sai sót khi code vội. Hãy thử làm "biên dịch viên" (compiler) cho đoạn code sau nhé.

Tôi có hàm tính chu vi hình chữ nhật:

```cpp
void tinhChuVi(int dai, int rong) {
  int ketQua = (dai + rong) * 2;
  cout << "Chu vi la: " << ketQua << "\n";
}

int main() {
  // Cau lenh A
  tinhChuVi(10, 5);
  
  // Cau lenh B
  tinhChuVi(5, 10);
  
  return 0;
}

```

**Câu hỏi:**

1. Kết quả của câu lệnh A và câu lệnh B có giống nhau không?
2. Nếu tôi thay đổi hàm thành `void tinhChia(int tuSo, int mauSo)` để làm phép chia, thì thứ tự (10, 5) và (5, 10) còn cho ra kết quả giống nhau nữa không?

Hãy suy nghĩ kỹ về "vai trò" của từng vị trí nhé!

Tuyệt vời! Câu trả lời hoàn toàn chính xác.

Bạn đã nhận ra bản chất cốt lõi:

* Với phép cộng (chu vi), thứ tự đôi khi không gây lỗi logic vì tính chất giao hoán ().
* Nhưng với các phép tính khác (chia, trừ, xử lý chuỗi...), **sai thứ tự là sai tất cả**.

Bây giờ, hãy chuẩn bị tinh thần. Chúng ta sẽ bước sang một chương thay đổi hoàn toàn cách bạn viết code.

---

## CHƯƠNG 4: RETURN VALUES (GIÁ TRỊ TRẢ VỀ)

**(Shipper giao hàng tận tay)**

### 1. Bức tranh toàn cảnh (The Big Picture)

Từ đầu đến giờ, chúng ta toàn dùng từ khóa `void`.

* `void` nghĩa là "hư vô/trống rỗng".
* Khi dùng `void`, hàm hoạt động giống như việc bạn hét lên một câu. Mọi người nghe thấy (hiện lên màn hình `cout`), nhưng sau đó âm thanh tan biến vào hư không. Bạn không thể "cầm nắm" âm thanh đó để làm việc khác được.

Bây giờ, chúng ta muốn hàm hoạt động giống như một **người thợ gia công**. Bạn đưa nguyên liệu (tham số), họ làm ra sản phẩm và **GỬI TRẢ (RETURN)** sản phẩm đó lại cho bạn.

> **Ẩn dụ:**
> * **Hàm Void:** Bạn nhờ nhân viên "Hát cho tôi nghe bài Chúc mừng sinh nhật". Họ hát xong là hết.
> * **Hàm Return:** Bạn nhờ nhân viên "Viết số tuổi của tôi lên cái bánh". Họ viết xong và **trả lại cái bánh** cho bạn. Bạn có thể cầm cái bánh đó để ăn, để tặng, hay để ném... tùy bạn.
> 
> 

### 2. Cấu trúc Code (Syntax)

Có 2 thay đổi lớn bạn phải chú ý:

1. Thay chữ `void` bằng **Kiểu dữ liệu** của kết quả (ví dụ `int`, `string`, `double`).
2. Bên trong hàm, bắt buộc phải có lệnh `return` + giá trị.

Hãy xem ví dụ tính tổng:

```cpp
#include <iostream>
using namespace std;

// THIET KE:
// Thay "void" bang "int" (vi tong cua 2 so nguyen la mot so nguyen)
int tinhTong(int x, int y) {
  // Thay vi cout, ta dung return
  return x + y;
}

int main() {
  // SU DUNG:
  // Vi ham tra ve mot gia tri, ta co the cat no vao bien khac
  int ketQua = tinhTong(5, 3);
  
  cout << "Tong la: " << ketQua << "\n";
  
  // Hoac dung truc tiep trong phep tinh khac
  // O day: tinhTong(5,3) bien thanh so 8, sau do 8 + 10 = 18
  cout << "Tong cong them 10 la: " << (tinhTong(5, 3) + 10);
  
  return 0;
}

```

### 3. Phân tích dòng chảy (Deep Dive)

Điều kỳ diệu xảy ra ở dòng `int ketQua = tinhTong(5, 3);`:

1. Máy tính chạy vào hàm `tinhTong`.
2. Tính `5 + 3 = 8`.
3. Lệnh `return 8` được kích hoạt.
4. Ngay lập tức, cụm từ `tinhTong(5, 3)` trong hàm main **biến mất** và được thay thế bằng số `8`.
5. Dòng code trở thành: `int ketQua = 8;`.

> **Sức mạnh:** Nhờ `return`, bạn có thể nối các hàm lại với nhau. Ví dụ: Dùng kết quả của hàm tính tổng để làm đầu vào cho hàm tính trung bình. `void` không làm được điều này!

---

### 🧠 KIỂM TRA SỰ HIỂU BIẾT (ACTIVE RECALL)

Phần này rất quan trọng vì 90% các hàm trong thực tế đều dùng `return`. Hãy thử giải bài toán này:

Tôi có hàm tính diện tích hình vuông:

```cpp
int dienTichVuong(int canh) {
  return canh * canh;
}

int main() {
  // Tôi muốn tính diện tích của 2 hình vuông rồi cộng lại
  int hinhA = dienTichVuong(5); // Canh = 5
  int hinhB = dienTichVuong(3); // Canh = 3
  
  // Hãy điền vào chỗ trống (...) để tính tổng diện tích
  int tongDienTich = ...; 
  
  cout << tongDienTich;
  return 0;
}

```

**Câu hỏi:**

1. Dòng `int tongDienTich = ...;` bạn sẽ viết code như thế nào?
2. Giá trị cuối cùng in ra màn hình là bao nhiêu?

Hãy trả lời để chứng minh bạn đã nhận được "hàng" từ Shipper nhé! Sau đó chúng ta sẽ sang **Chương 5** - phần "hack não" nhất của bài hôm nay.

Tuyệt vời! Bạn tính toán nhanh và chuẩn xác như một máy tính vậy. Kết quả `34` là hoàn toàn chính xác.

Bạn đang đi rất vững chắc. Bây giờ, hãy hít thở sâu một chút nhé. Chúng ta sắp bước vào **Chương 5**, nơi chứa đựng một "ma thuật" thực sự của C++. Đây là phần kiến thức phân loại giữa người biết code và người **hiểu** code.

---

## CHƯƠNG 5: PASS BY REFERENCE (TRUYỀN THAM CHIẾU)

**(Sửa trực tiếp vào bản gốc)**

### 1. Bức tranh toàn cảnh (The Big Picture)

Hãy tưởng tượng bạn viết một bài văn trên file Word.

* **Cách cũ (Pass by Value - Truyền tham trị):** Bạn gửi file đính kèm qua email cho bạn bè sửa. Họ tải về, sửa chữa nát bét trên máy họ. Nhưng file gốc trên máy bạn **vẫn y nguyên**, không thay đổi gì cả. (Đây là cách hoạt động của các chương trước).
* **Cách mới (Pass by Reference - Truyền tham chiếu):** Bạn không gửi file. Bạn gửi **đường link Google Docs** (quyền chỉnh sửa) cho bạn bè. Khi họ xóa một đoạn văn, trên màn hình của bạn đoạn văn đó cũng **biến mất ngay lập tức**.

> **Cốt lõi:** Pass by Reference cho phép hàm thò tay ra ngoài và thay đổi giá trị của biến gốc nằm ở hàm `main` (hoặc nơi gọi nó).

### 2. Cấu trúc Code (Syntax)

Bí mật nằm ở một ký tự nhỏ bé: Dấu và `&`.
Bạn đặt nó ngay sau kiểu dữ liệu trong phần khai báo tham số.

Ví dụ kinh điển nhất: Hàm hoán đổi giá trị (Swap).

```cpp
#include <iostream>
using namespace std;

// THIET KE:
// Chu y dau "&" sau chu "int"
// int &x nghia la: "Toi muon lay duong link toi bien x", chu khong phai gia tri copy
void hoanDoi(int &x, int &y) {
  int tam = x;
  x = y;
  y = tam;
}

int main() {
  int soThuNhat = 10;
  int soThuHai = 20;

  cout << "Truoc khi doi: " << soThuNhat << " - " << soThuHai << "\n";

  // Goi ham hoan doi
  hoanDoi(soThuNhat, soThuHai);

  cout << "Sau khi doi: " << soThuNhat << " - " << soThuHai << "\n";
  
  return 0;
}

```

**Kết quả màn hình:**

* Trước khi đổi: 10 - 20
* Sau khi đổi: 20 - 10 (Nó thực sự đã bị đảo ngược!)

### 3. Phân tích dòng chảy (Deep Dive) - Tại sao lại cần nó?

Nếu bạn bỏ dấu `&` đi, hàm `hoanDoi` sẽ chỉ hoán đổi 2 bản copy bên trong nó. Khi hàm kết thúc, 2 bản copy bị hủy, và `soThuNhat`, `soThuHai` ở ngoài vẫn trơ trơ ra đó (vẫn là 10 - 20).

**Lợi ích to lớn:**

1. **Thay đổi dữ liệu gốc:** Như ví dụ trên.
2. **Tối ưu hiệu suất (Performance):** Hãy tưởng tượng biến của bạn không phải là một con số, mà là một cuốn từ điển dày 5000 trang.
* Nếu không có `&`: Máy tính phải photo 5000 trang đó ra một bản sao để đưa vào hàm (Tốn bộ nhớ, tốn thời gian).
* Nếu có `&`: Máy tính chỉ đưa cái "địa chỉ" ngăn kéo chứa cuốn sách. Không cần photo gì cả. Cực nhanh!



---

### 🧠 KIỂM TRA SỰ HIỂU BIẾT (ACTIVE RECALL)

Đây là bài test quan trọng để xem bạn có bị lừa bởi "ảo ảnh" hay không.

Tôi có đoạn code sau:

```cpp
void tangGiaTri(int &a, int b) {
  a = a + 1;
  b = b + 1;
}

int main() {
  int x = 5;
  int y = 5;
  
  tangGiaTri(x, y);
  
  cout << "x = " << x << "\n";
  cout << "y = " << y << "\n";
  
  return 0;
}

```

**Câu hỏi:**

1. Giá trị của `x` sau khi chạy xong là bao nhiêu?
2. Giá trị của `y` sau khi chạy xong là bao nhiêu?

*(Gợi ý: Nhìn kỹ xem biến nào có dấu `&` (Link Google Docs) và biến nào không có (File đính kèm)).*

Hãy cho tôi biết kết quả dự đoán của bạn nhé!

Rất tiếc, câu trả lời chính xác phải là: **x = 6** và **y = 5**.

Bạn đã bị "chiếc bẫy" của C++ đánh lừa một chút ở biến `y`. Đừng lo, đây là lỗi phổ biến nhất khi mới học về tham chiếu. Hãy để tôi giải thích lại bằng hình ảnh cho bạn dễ nhớ:

1. **Với `x` (Đi vào `int &a`):**
* Có dấu `&` -> Đây là **Google Docs (Link)**.
* Hàm sửa trực tiếp vào link -> Bản gốc `x` bị thay đổi thành 6. (Bạn đúng phần này).


2. **Với `y` (Đi vào `int b`):**
* **KHÔNG** có dấu `&` -> Đây là **File đính kèm (Copy)**.
* Máy tính tạo ra một bản sao của `y`, gọi là `b`.
* Hàm cộng 1 vào `b` (bản sao `b` lên 6), nhưng bản gốc `y` nằm ở hàm main vẫn **an toàn và giữ nguyên** giá trị là 5.



> **Bài học xương máu:** Muốn thay đổi bản gốc, bắt buộc phải có cái "móc câu" `&`.

---

Bạn đã sẵn sàng chưa? Chúng ta sẽ đến với chương cuối cùng, nơi chúng ta không xử lý từng món lẻ tẻ nữa mà xử lý cả một "thùng hàng".

## CHƯƠNG 6: PASSING ARRAYS (TRUYỀN MẢNG)

**(Xử lý cả một thùng hàng)**

### 1. Bức tranh toàn cảnh (The Big Picture)

Đôi khi bạn không muốn đưa cho hàm một quả táo (biến đơn), mà muốn đưa cả một **két táo** (mảng/array) để hàm kiểm tra xem có quả nào bị hỏng không.

Điều thú vị nhất của mảng trong C++ là: **Mảng MẶC ĐỊNH luôn luôn là "Google Docs" (Tham chiếu).**
Bạn không cần dấu `&`. Khi bạn đưa một mảng vào hàm, bất cứ thay đổi nào bên trong hàm đều **tác động trực tiếp** lên mảng gốc.

> **Ẩn dụ:** Bạn đưa chìa khóa kho hàng cho nhân viên. Họ vào kho và sắp xếp lại đồ đạc. Khi họ ra về, kho hàng của bạn đã thực sự thay đổi.

### 2. Cấu trúc Code (Syntax)

Để khai báo một tham số là mảng, bạn dùng cặp ngoặc vuông `[]` sau tên tham số.

Ví dụ: Hàm in ra các số trong mảng.

```cpp
#include <iostream>
using namespace std;

// THIET KE:
// "int mangSo[]" nghia la ham nay chap nhan mot thung chua cac so nguyen
// Ta can them tham so "kichThuoc" de biet thung hang to co nao
void inMang(int mangSo[], int kichThuoc) {
  for (int i = 0; i < kichThuoc; i++) {
    cout << mangSo[i] << " ";
    
    // Thu sua doi gia tri truc tiep
    mangSo[i] = mangSo[i] * 2; 
  }
  cout << "\n";
}

int main() {
  // Tao mang goc
  int soYeuThich[3] = {1, 2, 3};
  
  // Goi ham: Chi can dua ten mang ("soYeuThich"), khong can ngoac vuong
  inMang(soYeuThich, 3);
  
  // Kiem tra lai mang goc
  cout << "So dau tien sau khi chay ham: " << soYeuThich[0];
  
  return 0;
}

```

### 3. Phân tích dòng chảy (Deep Dive)

1. Hàm `inMang` được gọi. Nó nhận lấy cái mảng `soYeuThich`.
2. Bên trong vòng lặp, dòng `mangSo[i] = mangSo[i] * 2` sẽ nhân đôi từng số.
3. Kết quả in ra trong hàm: `1 2 3`.
4. Dòng `cout` cuối cùng ở hàm main sẽ in ra: **`So dau tien sau khi chay ham: 2`**.
* Lý do: Số `1` ban đầu đã bị nhân đôi thành `2` vĩnh viễn, dù ta không hề dùng dấu `&`.



> **Ghi nhớ:** Với Mảng (Array), bạn luôn luôn thao tác trên dữ liệu gốc. Hãy cẩn thận!

---

### 🎓 TỔNG KẾT HÀNH TRÌNH

Chúc mừng bạn! Bạn đã hoàn thành xuất sắc khóa huấn luyện cấp tốc về **C++ Function Parameters**. Hãy cùng nhìn lại những công cụ bạn đã thu thập được:

1. **Parameters vs Arguments:** Cái khuôn và nguyên liệu.
2. **Default Parameters:** Chế độ mặc định cho người lười.
3. **Multiple Parameters:** Đúng thứ tự là chân ái.
4. **Return Values:** Shipper giao hàng về tận tay (thay vì chỉ hét lên rồi thôi).
5. **Pass by Reference (`&`):** Trao quyền sửa đổi bản gốc (Google Docs).
6. **Passing Arrays:** Luôn luôn sửa đổi bản gốc (Mặc định).

### 🚀 BƯỚC TIẾP THEO (NEXT STEP)

Để khắc sâu kiến thức này, tôi có một đề bài thử thách cuối cùng dành cho bạn (Final Boss):

> **Thử thách:** Hãy viết một hàm tên là `doiChoVaNhanDoi`.
> * Hàm nhận vào 2 số nguyên (dùng tham chiếu).
> * Nhiệm vụ: Hoán đổi vị trí của chúng, SAU ĐÓ nhân đôi giá trị của cả hai lên.
> * Ví dụ: Đầu vào `a=1, b=2`. Kết quả sau khi chạy hàm: `a=4, b=2`.
> 
> 

Bạn có muốn thử viết đoạn code này (hoặc ý tưởng code) gửi cho tôi kiểm tra không?

**CHÍNH XÁC TUYỆT ĐỐI! 💯**

Bạn đã giải quyết bài toán "Final Boss" này một cách hoàn hảo. Đoạn code của bạn ngắn gọn, đúng cú pháp và quan trọng nhất là **đúng tư duy**.

### Hãy cùng "chạy chậm" (Debug) lại tư duy của bạn:

1. **`void ... (int &a, int &b)`**: Bạn dùng dấu `&`. Đây là quyết định quan trọng nhất. Nó đảm bảo bạn đang sửa trực tiếp vào "bản gốc" chứ không phải bản photo.
2. **Swap (`temp`)**: Logic hoán đổi kinh điển.
* Giả sử ban đầu: `a = 1`, `b = 2`.
* Sau 3 dòng swap: `a = 2`, `b = 1`.


3. **Double (`*= 2`)**:
* `a` (đang là 2) * 2 = **4**.
* `b` (đang là 1) * 2 = **2**.



Kết quả cuối cùng biến gốc thay đổi thành: `4` và `2`. Hoàn toàn khớp với yêu cầu!

---

### TỔNG KẾT KHÓA HỌC

Bạn đã đi từ việc hiểu "cái phễu" (Parameter) đến việc làm chủ "quyền chỉnh sửa Google Docs" (Reference). Đây là những viên gạch nền tảng cực kỳ quan trọng để sau này bạn học về **Con trỏ (Pointers)** hay **Lập trình hướng đối tượng (OOP)**.

Hiện tại, bạn đã nắm vững phần **Function Parameters** trên W3Schools.

👉 **BƯỚC TIẾP THEO:**
Chủ đề tiếp theo trong lộ trình C++ thường là **Function Overloading** (Nạp chồng hàm) – *Nghệ thuật dùng 1 cái tên cho nhiều hàm khác nhau*.

Bạn có muốn "thừa thắng xông lên", khám phá **Function Overloading** ngay bây giờ không? (Hay bạn muốn dừng lại nghỉ ngơi?)