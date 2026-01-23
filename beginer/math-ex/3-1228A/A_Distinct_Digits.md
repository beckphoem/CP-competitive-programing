Chào bạn! Tôi đã sẵn sàng nhập vai **Algorithmic Coach** để cùng bạn chinh phục các thử thách trên Codeforces theo triết lý "Learning How to Learn". 🧠

Chúng ta sẽ không bắt đầu bằng những dòng code khô khan, mà sẽ bắt đầu bằng việc "mổ xẻ" logic để bạn thực sự làm chủ được bài toán.

---

## 🏗️ Phẫu thuật đề bài: 1228A - Distinct Digits

Nhiệm vụ của chúng ta trong bài này khá thẳng thắn khi lược bỏ các yếu tố rườm rà:

* **Dữ liệu vào:** Bạn được cho hai số nguyên  và .
* **Mục tiêu:** Tìm một số nguyên  nằm trong khoảng từ  đến  () sao cho **tất cả các chữ số của  đều khác nhau**.
* **Kết quả:** Nếu tìm được số thỏa mãn, hãy chỉ ra số đó (nếu có nhiều số, chỉ cần chọn một). Nếu không có số nào như vậy, hãy trả về .

### 🗺️ Lộ trình tư duy của chúng ta:

1. **Mảnh ghép 1:** Hiểu thế nào là "các chữ số khác nhau" (Distinct Digits).
2. **Mảnh ghép 2:** Chiến thuật "quét" qua các con số trong một phạm vi.
3. **Mảnh ghép 3:** Cách kiểm tra từng con số (Xử lý bẫy logic).

---

### 🧩 Mảnh ghép 1: Thế nào là "các chữ số khác nhau"?

Hãy tưởng tượng mỗi chữ số trong một số là một viên bi có màu sắc khác nhau. Nếu số đó có các chữ số "distinct", nghĩa là trong túi của bạn không có hai viên bi nào cùng màu.

* Ví dụ: Số  có các chữ số  → **Hợp lệ** (không trùng).
* Ví dụ: Số  có các chữ số  → **Không hợp lệ** (số  xuất hiện 2 lần).

⚠️ **Bẫy logic:** Nhiều bạn thường chỉ nghĩ đến việc so sánh các chữ số đứng cạnh nhau, nhưng thực tế chúng ta phải kiểm tra **tất cả** các vị trí.

❓ **Thử thách tư duy dành cho bạn:**
Trong các số sau đây, số nào thỏa mãn điều kiện "tất cả chữ số khác nhau"?

1. 
2. 
3. 
4. 

Bạn hãy chọn các số đúng và thử giải thích ngắn gọn: Làm sao để một chiếc máy tính có thể "nhớ" được nó đã nhìn thấy chữ số nào rồi để biết là có bị trùng hay không?

Tôi sẽ chờ câu trả lời của bạn trước khi chúng ta sang bước tiếp theo! 🚀

Chính xác! Bạn đã chọn đúng những số có các chữ số khác nhau:

* **1024** ✅: Các chữ số là , không có số nào lặp lại.
* **9876** ✅: Các chữ số là , hoàn toàn riêng biệt.

Còn **11** và **1212** bị loại vì có sự lặp lại (số  hoặc số ).

Để trả lời câu hỏi "Làm sao máy tính nhớ được?", có một cách rất hay là dùng một **"Danh sách đánh dấu"** (giống như một bảng danh sách điểm danh 📋).

Hãy tưởng tượng bạn có 10 cái hộp được đánh số từ  đến :

1. Khi máy tính nhìn thấy chữ số , nó kiểm tra hộp số .
2. Nếu hộp số  đang trống, nó bỏ một "viên sỏi" vào đó để đánh dấu: "Tôi đã thấy số 2 rồi nhé!".
3. Nếu nó lại thấy một số  nữa, nó nhìn vào hộp số  và thấy đã có sỏi rồi ➡ **"A ha! Trùng rồi!"**.

---

### 🧩 Mảnh ghép 2: Chiến thuật "Quét" (Brute Force)

Đề bài yêu cầu tìm một số  thỏa mãn điều kiện trong khoảng từ  đến .
Vì giới hạn của  và  trong bài này khá nhỏ (chỉ đến ), máy tính có thể chạy rất nhanh. Chiến thuật đơn giản nhất là: **Thử từng số một**.

Chúng ta sẽ đi từ  cho đến .

* Nếu gặp một số thỏa mãn ➡ **In ra ngay** và dừng lại.
* Nếu đi hết đến  mà vẫn không thấy ➡ **In ra -1**.

---

### 🧩 Mảnh ghép 3: Cách "mổ xẻ" một con số

Đây là phần quan trọng nhất để chuyển từ tư duy sang mã giả. Làm thế nào để lấy ra từng chữ số của một số (ví dụ số ) để cho vào "hộp đánh dấu"?

Trong lập trình, chúng ta thường dùng hai phép toán "thần thánh" với số **10**:

1. **Phép chia lấy dư (`% 10`)**: Để lấy chữ số cuối cùng.
*  (Lấy được số ).


2. **Phép chia nguyên (`/ 10`)**: Để vứt bỏ chữ số cuối đã lấy xong.
*  (Còn lại số  để tiếp tục xét).



❓ **Thử thách tư duy tiếp theo:**
Giả sử chúng ta đang kiểm tra số **121**. Theo bạn, quy trình "bỏ sỏi vào hộp" sẽ diễn ra như thế nào qua từng bước chia cho 10?

Hãy mô tả ngắn gọn: Ở bước nào thì máy tính sẽ phát hiện ra là số **121** không hợp lệ?

Bạn đã nắm bắt rất đúng thời điểm mấu chốt! 🎯

Với số **121**, quy trình "bỏ sỏi vào hộp" sẽ diễn ra như sau:

1. **Lần 1:** . Máy tính kiểm tra hộp số 1 (đang trống) và bỏ 1 viên sỏi vào đó. Sau đó .
2. **Lần 2:** . Máy tính kiểm tra hộp số 2 (đang trống) và bỏ 1 viên sỏi vào đó. Sau đó .
3. **Lần 3:** . Máy tính kiểm tra hộp số 1 và thấy **đã có sỏi rồi**. 🛑 **Dừng lại ngay!** Đây chính là lúc nó kết luận số 121 không hợp lệ.

---

### 🧩 Mảnh ghép cuối: Lắp ráp thành thuật toán

Bây giờ chúng ta đã có đủ các mảnh ghép. Hãy cùng tổng hợp lại thành một lộ trình hoàn chỉnh cho máy tính (Mã giả - Pseudocode).

**Chiến thuật tổng quát:**

1. Chạy một vòng lặp từ  đến . Gọi số hiện tại đang xét là `i`.
2. Với mỗi số `i`, ta thực hiện:
* Tạo một **danh sách đánh dấu** (10 chiếc hộp trống).
* Dùng vòng lặp (trong khi số `i` vẫn còn chữ số) để tách từng chữ số bằng `% 10` và `/ 10`.
* Nếu chữ số vừa tách đã được đánh dấu trong hộp ➡ Số này "hỏng", bỏ qua và xét số tiếp theo.
* Nếu tách hết các chữ số mà không thấy trùng ➡ **Tìm thấy rồi!** In số `i` ra và kết thúc chương trình.


3. Nếu chạy hết vòng lặp từ  đến  mà không tìm được số nào ➡ In ra .

---

❓ **Câu hỏi cuối cùng để chốt lại tư duy:**

Theo bạn, tại sao ở mỗi số `i` mới (ví dụ khi vừa kiểm tra xong số 121 và chuyển sang số 122), chúng ta bắt buộc phải **làm trống lại 10 chiếc hộp đánh dấu**? Chuyện gì sẽ xảy ra nếu ta quên không làm việc này? 🧺✨

Chính xác! Mỗi con số là một "ứng cử viên" mới, nên chúng ta phải dọn sạch các hộp (reset danh sách đánh dấu) để đảm bảo kết quả của số trước không làm ảnh hưởng đến số sau. 🧹✨

Nếu chúng ta quên không làm trống hộp, thì các chữ số của số  (đã bị đánh dấu) sẽ vẫn còn đó khi ta kiểm tra số . Máy tính sẽ thấy hộp số  và số  đã có sỏi, dẫn đến việc kết luận sai rằng mọi số tiếp theo đều không hợp lệ.

---

### 📝 Tổng kết thuật toán (Mã giả)

Để bạn dễ dàng chuyển hóa tư duy này thành ngôn ngữ lập trình (như C++ hay Python), đây là bản tóm tắt các bước theo ngôn ngữ "nửa người nửa máy":

```text
NHAP l, r
CHO biến x chạy từ l đến r:
    Tạo một mảng đánh dấu 'da_xuat_hien' gồm 10 phần tử (tất cả bằng False)
    Biến 'tam' = x
    Biến 'hop_le' = True
    
    TRONG KHI 'tam' > 0:
        chu_so = 'tam' % 10
        NEU 'da_xuat_hien'[chu_so] la True:
            'hop_le' = False
            THOAT vòng lặp tách chữ số
        da_xuat_hien[chu_so] = True
        'tam' = 'tam' / 10
        
    NEU 'hop_le' la True:
        IN ra x
        KET THUC chuong trinh
        
IN ra -1 (nếu chạy hết vòng lặp mà không tìm thấy)

```

### 💡 Bước tiếp theo dành cho bạn

Bạn đã nắm rất vững tư duy giải quyết bài này rồi! Để thực sự làm chủ kiến thức, bạn muốn làm gì tiếp theo?

1. **Thử thách nâng cao:** Nếu  không phải là  mà là  (), liệu cách "quét từng số" này còn hiệu quả không? Tại sao?
2. **Thực hành:** Bạn có muốn tôi hỗ trợ viết mã nguồn (code) cụ thể cho bài này bằng một ngôn ngữ nào đó không?
3. **Bài toán mới:** Chúng ta chuyển sang "mổ xẻ" một bài toán khác trên Codeforces nhé? (Ví dụ: bài **71A - Way Too Long Words**)	