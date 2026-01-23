Chào bạn! Tôi đã nắm vững vai trò **Huấn luyện viên Tư duy Thuật toán** theo triết lý "Learning How to Learn". Chúng ta sẽ cùng nhau "mổ xẻ" bài toán **Codeforces 1325A - EhAb AnD gCd** này nhé. 🧠

---

### 1. Phẫu thuật đề bài (Deconstruct) 🔪

Loại bỏ những câu chuyện phiếm về tên gọi, bản chất yêu cầu của bài toán cực kỳ ngắn gọn:

* **Đầu vào (Input):** Cho bạn một số nguyên dương .
* **Nhiệm vụ (Output):** Tìm **hai số nguyên dương**  và  bất kỳ, sao cho khi thực hiện phép toán sau đây, kết quả phải bằng đúng :



> 💡 **Giải thích ẩn dụ:**
> * **GCD (Ước chung lớn nhất):** Hãy tưởng tượng  và  là hai sợi dây thừng.  là độ dài của cái "thước đo" dài nhất mà bạn có thể dùng để đo vừa khít cả hai sợi dây đó. 📏
> * **LCM (Bội chung nhỏ nhất):** Hãy tưởng tượng  và  là hai vận động viên chạy trên một vòng đua.  là quãng đường ngắn nhất để cả hai người cùng gặp lại nhau tại điểm xuất phát. 🏃‍♂️🏃‍♀️
> 
> 

---

### 2. Lộ trình tư duy (Roadmap) 🗺️

Để giải bài này, chúng ta sẽ đi qua 2 mảnh ghép (Chunks):

* **Chunk 1:** Khám phá mối quan hệ giữa các số đặc biệt (Số 1 có quyền năng gì?).
* **Chunk 2:** Tìm ra "công thức vạn năng" để luôn thắng mọi bộ dữ liệu.

---

### 3. Mảnh ghép 1: Sức mạnh của số 1 🛡️

Trong thế giới của  và , số  là một con số cực kỳ "hiền lành" và dễ đoán.

👉 **Logic:** * Nếu tôi có một số  và một số bất kỳ (ví dụ số ), thì cái thước dài nhất đo được cả  và  chỉ có thể là .

* Nếu tôi có một số  và một số , thì quãng đường ngắn nhất để cả hai "gặp nhau" chính là số  (vì  chia hết cho cả  và ).

❓ **Thử thách tư duy:**
Giả sử tôi chọn  và .

1. Kết quả của  là bao nhiêu?
2. Kết quả của  là bao nhiêu?
3. Tổng của  bằng bao nhiêu?

Hãy tính thử xem kết quả tổng đó có mối liên hệ gì với các số  mà ta đã chọn không nhé! Bạn đã sẵn sàng chưa?

Chào bạn! Tôi đã nắm vững vai trò **Huấn luyện viên Tư duy Thuật toán** theo triết lý "Learning How to Learn". Chúng ta sẽ cùng nhau "mổ xẻ" bài toán **Codeforces 1325A - EhAb AnD gCd** này nhé. 🧠

---

### 1. Phẫu thuật đề bài (Deconstruct) 🔪

Loại bỏ những câu chuyện phiếm về tên gọi, bản chất yêu cầu của bài toán cực kỳ ngắn gọn:

* **Đầu vào (Input):** Cho bạn một số nguyên dương .
* **Nhiệm vụ (Output):** Tìm **hai số nguyên dương**  và  bất kỳ, sao cho khi thực hiện phép toán sau đây, kết quả phải bằng đúng :



> 💡 **Giải thích ẩn dụ:**
> * **GCD (Ước chung lớn nhất):** Hãy tưởng tượng  và  là hai sợi dây thừng.  là độ dài của cái "thước đo" dài nhất mà bạn có thể dùng để đo vừa khít cả hai sợi dây đó. 📏
> * **LCM (Bội chung nhỏ nhất):** Hãy tưởng tượng  và  là hai vận động viên chạy trên một vòng đua.  là quãng đường ngắn nhất để cả hai người cùng gặp lại nhau tại điểm xuất phát. 🏃‍♂️🏃‍♀️
> 
> 

---

### 2. Lộ trình tư duy (Roadmap) 🗺️

Để giải bài này, chúng ta sẽ đi qua 2 mảnh ghép (Chunks):

* **Chunk 1:** Khám phá mối quan hệ giữa các số đặc biệt (Số 1 có quyền năng gì?).
* **Chunk 2:** Tìm ra "công thức vạn năng" để luôn thắng mọi bộ dữ liệu.

---

### 3. Mảnh ghép 1: Sức mạnh của số 1 🛡️

Trong thế giới của  và , số  là một con số cực kỳ "hiền lành" và dễ đoán.

👉 **Logic:** * Nếu tôi có một số  và một số bất kỳ (ví dụ số ), thì cái thước dài nhất đo được cả  và  chỉ có thể là .

* Nếu tôi có một số  và một số , thì quãng đường ngắn nhất để cả hai "gặp nhau" chính là số  (vì  chia hết cho cả  và ).

❓ **Thử thách tư duy:**
Giả sử tôi chọn  và .

1. Kết quả của  là bao nhiêu?
2. Kết quả của  là bao nhiêu?
3. Tổng của  bằng bao nhiêu?

Hãy tính thử xem kết quả tổng đó có mối liên hệ gì với các số  mà ta đã chọn không nhé! Bạn đã sẵn sàng chưa?

Chính xác! Bạn tính toán rất nhanh. ⚡

Khi  và , ta có:

* 
* 
* **Tổng:** 

Bạn có nhận thấy điều gì thú vị không? Tổng  đúng bằng . Và quan trọng hơn, tổng này cũng chính là .

Bây giờ, hãy thử tổng quát hóa lên một chút. Nếu tôi đưa cho bạn một số  bất kỳ (ví dụ  hoặc ), và tôi luôn chọn cố định số đầu tiên là ****.

Theo bạn, số **** còn lại phải bằng bao nhiêu để tổng  luôn bằng đúng ? (Gợi ý: Hãy nhìn lại ví dụ  ở trên nhé!) 💡

Để tìm ra số  khi đã biết , chúng ta hãy nhìn vào quy luật mà bạn vừa khám phá ra:

Với , nếu chọn  thì  (vì ).
Với , nếu chọn  thì  sẽ là bao nhiêu để ?

💡 **Gợi ý:**  luôn luôn bằng , và  luôn luôn bằng chính số  đó.

Vậy với một số  bất kỳ (ví dụ ), nếu ta chọn  thì số  phải là bao nhiêu để tổng của chúng bằng ?

Quá chuẩn luôn! 🎯

Vì  luôn là  và  luôn là , nên tổng của chúng sẽ là . Để tổng này bằng , ta chỉ cần chọn .

Đây chính là "chìa khóa" vạn năng 🔑 giúp bạn giải quyết bài toán này với bất kỳ giá trị  nào mà đề bài đưa ra.

---

### 4. Tổng kết & Mã giả (Pseudocode) 📝

Như vậy, chiến thuật của chúng ta là:

1. Nhận vào số .
2. Luôn luôn in ra hai số:  và .

**Mã giả:**

```text
Nhap vao so luong bo test t
Lap t lan:
    Nhap vao so x
    In ra: 1 va (x - 1)

```

### 5. Kiểm tra bẫy logic (Edge Case) ⚠️

Đề bài cho biết  nằm trong khoảng .

* Nếu , thuật toán của bạn sẽ in ra gì?
* Kết quả đó có thỏa mãn điều kiện  là các số nguyên dương () không?

Nếu bạn thấy trường hợp nhỏ nhất này vẫn ổn, thì bạn đã hoàn thành bài tập này một cách xuất sắc rồi đấy! Bạn có muốn tôi hỗ trợ viết mã C++ hoặc Python cho bài này không, hay chúng ta sang một bài toán mới thú vị hơn? 🚀

Chính xác! Với , thuật toán sẽ in ra **1 1**.

Kiểm tra lại điều kiện:

*  đều là các số nguyên dương (thỏa mãn ).
* 
* 
*  (đúng bằng ).

Vậy là chiến thuật ** và ** hoạt động hoàn hảo cho mọi trường hợp của bài toán này! ✨

---

### 🏁 Tổng kết bài tập

Chúng ta đã đi từ việc quan sát các ví dụ cụ thể đến việc tìm ra một "tính chất bất biến":

> **** và **** với mọi số nguyên dương .

Nhờ đó, thay vì phải tìm kiếm vất vả giữa hàng tỉ cặp số, chúng ta chỉ cần dùng đúng một công thức cố định. Đây chính là tư duy "đơn giản hóa vấn đề" trong lập trình thi đấu.

**Bạn muốn tiếp tục với thử thách nào tiếp theo?**

1. **Luyện tập thêm:** Giải một bài tương tự về tính chất số học (ví dụ: bài liên quan đến ước số).
2. **Thử thách mới:** Chuyển sang một chủ đề khác như mảng (Array) hoặc chuỗi (String).
3. **Xem mã nguồn:** Nếu bạn muốn tham khảo cách viết code hoàn chỉnh cho bài này.

Bạn chọn số mấy? 😊