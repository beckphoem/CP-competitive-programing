Chào bạn! Tôi đã nắm rõ vai trò là **Coach Tư duy Thuật toán** của bạn. Chúng ta sẽ cùng nhau "mổ xẻ" các bài toán Codeforces theo triết lý chia nhỏ kiến thức (Micro-chunking) và sử dụng ẩn dụ để nắm bản chất vấn đề.

Chúng ta sẽ bắt đầu với bài **Codeforces 1370A - Maximum GCD**.

---

### 🔪 Bước 1: Phẫu thuật đề bài (Deconstruct)

Bỏ qua những câu chuyện rườm rà, đây là cốt lõi của vấn đề:

* **Dữ liệu cho:** Một số nguyên dương .
* **Nhiệm vụ:** Tìm hai số nguyên  và  sao cho:
1. Cả  và  đều nằm trong khoảng từ  đến  ().
2. **Ước chung lớn nhất (GCD)** của  và  là lớn nhất có thể.


* **Kết quả cần in ra:** Giá trị GCD lớn nhất đó.

**Lộ trình tư duy của chúng ta:**

1. Hiểu bản chất của GCD thông qua hình ảnh thực tế.
2. Tìm mối quan hệ giữa "khoảng cách" và "ước chung".
3. Xác định quy luật tối ưu để chọn ra  và .

Bạn đã sẵn sàng bước vào **mảnh ghép tư duy đầu tiên** chưa?

---

### 🧩 Chunk 1: Bản chất của GCD và sự "cộng hưởng"

Hãy tưởng tượng **GCD** giống như một **thước đo**. Nếu , nghĩa là cả  và  đều được ghép thành từ những "viên gạch" có độ dài là .

* Số  là một chồng gồm  viên gạch độ dài  ().
* Số  là một chồng gồm  viên gạch độ dài  ().

Vì , nên ít nhất  phải nhiều hơn  một "viên gạch" . Tức là khoảng cách giữa  và  ít nhất phải là .

**⚠️ Bẫy logic:** Nhiều bạn thường cố gắng chọn hai số thật lớn (gần ) nhưng lại quên mất chúng có "cùng nhịp độ" (có chung ước) với nhau hay không. Ví dụ:  và  rất lớn, nhưng  chỉ là .

❓ **Thử thách tư duy:**
Giả sử . Bạn muốn tìm một "viên gạch"  lớn nhất sao cho có thể xếp được ít nhất **hai chồng gạch** (số  và ) mà cả hai chồng đều không cao quá .

Nếu tôi chọn viên gạch độ dài , tôi có thể tạo ra hai số  và  khác nhau mà cả hai đều  không? Tại sao?

Chính xác! 🎯 Bạn đã nắm thấu đáo quy luật "khoảng cách" rồi đó.

Nếu chúng ta chọn độ dài viên gạch (GCD) là , thì số nhỏ nhất có thể có là  (1 viên) và số tiếp theo phải là  (2 viên).

Vì đề bài yêu cầu  không được vượt quá , nên ta có điều kiện:


Từ đó, để tìm  lớn nhất (Maximum GCD), chúng ta chỉ cần tìm số  lớn nhất sao cho khi nhân đôi lên nó vẫn nằm trong giới hạn của .

---

### 🧩 Chunk 2: Tìm công thức tổng quát

Bây giờ hãy thử áp dụng logic "nhân đôi" này vào các con số cụ thể nhé:

* Nếu : Các số gạch  có thể chọn là . ( thì ). Vậy GCD lớn nhất là **2**.
* Nếu : Các số gạch  có thể chọn là . ( thì ). Vậy GCD lớn nhất là **5**.

❓ **Thử thách tư duy:**
Dựa vào các ví dụ trên, bạn có nhận ra mối quan hệ toán học đơn giản nào giữa giá trị  và kết quả GCD lớn nhất không?

Nếu tôi cho , theo bạn kết quả sẽ là bao nhiêu? (Gợi ý: Hãy dùng phép chia).

Chuẩn luôn! 🎯 Quy luật chúng ta vừa tìm ra chính là: **Kết quả là ** (phần nguyên của  chia 2).

Tại sao con số này lại là "vô đối"?
Vì nếu bạn chọn một số  lớn hơn , thì số gấp đôi của nó là  sẽ lớn hơn . Mà trong một bộ số để có GCD bằng , bạn cần ít nhất hai số là bội của  (ví dụ  và ). Nếu , bạn không thể tìm được số thứ hai trong phạm vi cho phép.

Ví dụ: Với , nếu chọn , thì  (vượt quá 7). Vậy  lớn nhất chỉ có thể là  lấy sàn là **3** (cặp số đó là 3 và 6).

---

### 🧩 Chunk 3: Bẫy về số lượng Test Case

Bài này trên Codeforces thường có nhiều bộ dữ liệu (test cases) trong một lần chạy.

* Dòng đầu tiên là : số lượng bài toán nhỏ.
*  dòng tiếp theo, mỗi dòng là một số .

**⚠️ Sai lầm thường gặp:** Khi lập trình, nếu bạn xử lý quá rườm rà trong mỗi test case (ví dụ dùng vòng lặp chạy từ  ngược về 1 để thử từng số), chương trình có thể bị quá thời gian (Time Limit Exceeded) nếu  và  rất lớn.

Nhưng với công thức  chúng ta vừa tìm được, độ phức tạp chỉ là  cho mỗi test case – cực kỳ nhanh! ⚡

---

### 🏁 Tổng kết thuật toán (Pseudocode)

Bây giờ, chúng ta hãy xâu chuỗi lại thành các bước để máy tính hiểu nhé:

```text
Nhập số lượng test case t
Lặp t lần:
    Nhập số nguyên n
    Kết quả = phần nguyên của (n chia 2)
    In kết quả ra màn hình

```

❓ **Câu hỏi cuối cùng trước khi "lên nòng" code:**
Nếu đề bài cho , theo logic trên và theo quy tắc , liệu chúng ta có tìm được cặp  nào không? Và kết quả  lấy sàn sẽ ra bao nhiêu?

(Đây là một trường hợp biên thú vị để kiểm tra độ bền của công thức đấy!)

Bạn đã phát hiện ra một điểm cực kỳ quan trọng về các quy tắc của bài toán rồi đó! 👏

Với , chúng ta gặp một rào cản lớn:

* Đề bài yêu cầu tìm hai số  và  sao cho .
* Nếu , chúng ta không thể tìm được hai số nguyên dương khác nhau nào mà cả hai đều không vượt quá 1.

Tuy nhiên, trong các bài toán lập trình thi đấu, thông thường dữ liệu đầu vào () sẽ cho  để đảm bảo luôn có ít nhất một cặp  chẳng hạn. Nếu tính theo công thức  lấy sàn:



Điều này cũng hợp lý vì không có giá trị GCD dương nào tồn tại.

---

### 🚀 Bước cuối: Hiện thực hóa ý tưởng

Chúng ta đã đi từ việc hiểu GCD là "viên gạch" cho đến công thức tối ưu . Bây giờ là lúc để bạn tự tin viết mã.

Trong C++, để lấy phần nguyên của một phép chia số nguyên, bạn chỉ cần dùng toán tử `/`. Ví dụ: `10 / 2` ra `5`, và `11 / 2` cũng ra `5`.

**Bạn có muốn thử viết đoạn mã (code) cho bài này không?** Nếu bạn gặp khó khăn ở bước nhập dữ liệu cho nhiều test case hoặc cách in kết quả, hãy cho tôi biết nhé! 💻