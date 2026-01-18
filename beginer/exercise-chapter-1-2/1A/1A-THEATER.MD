Chào bạn, đây là bài toán **Theatre Square (1A)** trên Codeforce. Đây là một bài toán kinh điển dành cho người mới bắt đầu, tuy nhiên rất nhiều bạn bị "lừa" ở những chi tiết nhỏ.

Để giải thích cho học sinh cấp 2, chúng ta sẽ không nói về code vội, mà hãy tưởng tượng đây là một bài toán **lát nền nhà** trong thực tế.

---

### 1. Hình dung bài toán

Hãy tưởng tượng bạn có một cái sân hình chữ nhật kích thước  (chiều dài là , chiều rộng là ). Bạn cần lát sân này bằng những viên gạch hình vuông có cạnh là .

**Quy tắc:**

* Các viên gạch không được cắt nhỏ.
* Bạn được phép lát thừa ra ngoài mép sân, nhưng **không được để hở** bất kỳ chỗ nào trong sân.
* Các viên gạch phải đặt song song với các cạnh của sân (không được đặt chéo).

### 2. Sai lầm thường gặp: Tính theo diện tích

Nhiều bạn học sinh sẽ nghĩ ngay đến công thức:

> "Tính diện tích sân (), sau đó chia cho diện tích một viên gạch ()."

**Cách này SAI.**

* **Ví dụ:** Sân kích thước , gạch kích thước .
* Diện tích sân là 5. Diện tích gạch là 4. Phép chia  viên.
* Nhưng thực tế, chiều rộng sân là 1, gạch là 2 (đủ che). Chiều dài sân là 5, gạch là 2. Bạn cần 3 viên gạch (, che đủ 5) mới lát hết chiều dài.
* Vậy thực tế bạn cần  viên gạch, chứ không phải con số liên quan đến diện tích.

### 3. Tư duy đúng: Chia theo từng cạnh (Hàng và Cột)

Thay vì tính diện tích, hãy tính xem **cần bao nhiêu viên gạch cho chiều dài** và **bao nhiêu viên cho chiều rộng**, sau đó nhân chúng lại.

Chúng ta tách bài toán làm 2 phần nhỏ:

1. **Chiều dài  cần bao nhiêu viên gạch cạnh ?**
2. **Chiều rộng  cần bao nhiêu viên gạch cạnh ?**

#### Phân tích phép chia (Làm tròn lên)

Giả sử chiều dài sân là , viên gạch .

* Viên thứ 1 che được từ 0 đến 3.
* Viên thứ 2 che được từ 3 đến 6.
* Vẫn còn dư 1 mét (từ 6 đến 7). Vì không được cắt gạch, ta bắt buộc phải dùng thêm **viên thứ 3**.

 Đây gọi là phép chia lấy phần nguyên và **làm tròn lên** (Ceiling).

* Nếu  chia hết cho  (ví dụ ): Số viên = .
* Nếu  không chia hết cho  (ví dụ ): Số viên = (phần nguyên của ) + 1.

### 4. Công thức tổng quát

Gọi  là số viên gạch cần cho chiều dài .
Gọi  là số viên gạch cần cho chiều rộng .

Số viên gạch cần thiết = .

Để máy tính hiểu được "làm tròn lên" mà không dùng hàm phức tạp, các lập trình viên thường dùng mẹo số học này:



*(Đây là phép chia lấy phần nguyên. Nếu  chia hết cho , cộng thêm  không làm thay đổi kết quả. Nếu  dư 1 chút, cộng thêm  sẽ giúp kết quả nhảy lên 1 đơn vị).*

### 5. "Cái bẫy" lớn nhất: Số quá lớn (Data Type)

Đây là lý do chính khiến nhiều người nộp bài bị sai (Wrong Answer) ở các test lớn.

* Trong đề bài,  và  có thể lên tới  (1 tỷ).
* Nếu  và gạch rất nhỏ (), bạn sẽ cần  viên gạch.
* Trong lập trình C++ hoặc Java, kiểu số nguyên bình thường (`int`) chỉ chứa được tối đa khoảng .
* Số  lớn hơn sức chứa của `int` rất nhiều.

**Giải pháp:** Bạn phải dùng kiểu biến chứa được số lớn (trong C++ là `long long`).

---

### Tóm tắt các bước giải (Thuật toán)

1. Đọc vào 3 số .
2. Sử dụng kiểu dữ liệu số lớn (`long long`).
3. Tính số viên gạch cho cạnh : Nếu chia hết thì lấy , nếu dư thì lấy .
4. Tính số viên gạch cho cạnh  tương tự.
5. Nhân 2 kết quả đó lại và in ra màn hình.

Bạn có muốn tôi thử gợi ý cách viết công thức toán học cho phần "làm tròn lên" này trong C++ để bạn tự viết code không?


### 1. Vấn đề của máy tính: "Cụt đuôi"

Trong C++ (và nhiều ngôn ngữ lập trình), khi bạn chia 2 số nguyên, máy tính luôn **làm tròn xuống** (bỏ phần thập phân).

Ví dụ: Bạn có kẹo (`n`) và muốn chia vào các hộp, mỗi hộp chứa được `a` cái.

* **Trường hợp 1 (Chia hết):** .
* . (Cần đúng 3 hộp).  Máy tính ra **3**. (Đúng)


* **Trường hợp 2 (Chia dư):** .
* Thực tế: Bạn cần 3 hộp đầy và 1 hộp nữa cho viên kẹo dư. Tổng là **4** hộp.
* Máy tính:   Nó cắt bỏ `.25` và chỉ trả về **3**. (Sai, thiếu mất 1 hộp).



 **Mục tiêu:** Làm sao để nếu dư dù chỉ 1 viên kẹo, máy tính cũng phải tự động cộng thêm 1 hộp?

### 2. Chiến thuật: "Đổ thêm cho đầy"

Hãy tưởng tượng cái hộp chứa được `a` viên kẹo.

* Để kích hoạt việc "nhảy sang hộp mới", ta sẽ gian lận bằng cách **đổ thêm ảo** một lượng kẹo vào `n` trước khi chia.
* Lượng đổ thêm này phải **gần bằng 1 hộp**, nhưng **không được bằng 1 hộp**.
* Lượng kẹo tối đa có thể đổ thêm mà không làm sai trường hợp chia hết chính là: **`a - 1`**.



### 3. Tại sao lại là `n + a - 1`?

Hãy xem xét công thức `(n + a - 1) / a` hoạt động thế nào qua 2 ví dụ trên nhé:

**Ví dụ A: Trường hợp có dư (n = 13, a = 4)**

* Ta cần kết quả là **4**.
* Áp dụng công thức: .
* 
* 
* .
* **Giải thích:** Vì 13 chia 4 dư 1, nên chỉ cần cộng thêm 3 đơn vị nữa là đủ để tạo thành một bộ 4 mới (1 + 3 = 4). Phép chia số nguyên sẽ nhảy lên 1 đơn vị.  **Đúng!**

**Ví dụ B: Trường hợp chia hết (n = 12, a = 4)**

* Ta cần kết quả giữ nguyên là **3** (không được nhảy lên 4).
* Áp dụng công thức: .
* 
* 
* Máy tính lấy 15 chia 4 được 3.75  Cắt đuôi còn **3**.
* **Giải thích:** Vì 12 đã chia hết, nên việc cộng thêm 3 (nhỏ hơn 4) **không đủ sức** để tạo ra một hộp mới. Phần dư thêm vào này bị máy tính cắt bỏ đi.  **Vẫn đúng!**

### Tóm lại

Công thức `(n + a - 1) / a` hoạt động theo logic:

1. Nếu `n` chia hết cho `a`: Việc cộng thêm `a-1` không đủ để tăng thương số lên, phép chia nguyên sẽ gạt bỏ phần thừa đó đi.
2. Nếu `n` chia dư: Việc cộng thêm `a-1` cộng với phần dư có sẵn chắc chắn sẽ lớn hơn hoặc bằng `a`, giúp thương số nhảy lên 1 đơn vị (tương đương làm tròn lên).

Đây là cách cực nhanh để tính  trong lập trình mà không sợ sai số thực!

Code của bạn viết rất chuẩn và cực kỳ dễ hiểu cho người mới bắt đầu! Đây chính là cách triển khai "thủ công" của phép toán **Làm tròn lên (Ceiling Function)** mà không cần dùng hàm có sẵn của thư viện toán học.

Để giải thích hướng tiếp cận `if-else` này cho học sinh cấp 2, chúng ta sẽ dùng hình ảnh **"Đi xe buýt"**.

---

### Giải thích logic `if-else` (Nguyên lý: "Thừa thì phải thêm")

Hãy tưởng tượng  là **tổng số học sinh** đi tham quan, và  là **số ghế của một chiếc xe buýt**.

Nhiệm vụ: Cần thuê bao nhiêu chiếc xe để chở hết  học sinh? (Không được để ai ở lại).

#### 1. Trường hợp 1: Chia hết (`if (n % a == 0)`)

* **Ví dụ:** Có  học sinh, xe có  chỗ.
* **Phép tính:**  chia  được , dư .
* **Thực tế:** Vừa xinh! Chỉ cần đúng 5 chiếc xe là đủ.
* **Code:** `x = n / a;`

#### 2. Trường hợp 2: Có dư (`else`)

* **Ví dụ:** Có  học sinh, xe vẫn  chỗ.
* **Phép tính:**  chia  được  (xe đầy), nhưng còn dư **3 em**.
* **Thực tế:** 3 em này không thể chạy bộ được. Bạn bắt buộc phải thuê thêm **1 chiếc xe nữa** cho 3 em này ngồi (dù xe đó sẽ còn trống nhiều chỗ).
* **Kết quả:** Cần  chiếc xe.
* **Code:** `x = n / a + 1;` (Phần nguyên cộng thêm 1).

---

### Tóm tắt tư duy

Đoạn code trên đang xử lý bài toán **lấp đầy khoảng trống**:

1. **Phép chia nguyên (`/`):** Máy tính chỉ cho biết lấp đầy được bao nhiêu phần trọn vẹn.
2. **Phép chia dư (`%`):** Máy tính kiểm tra xem còn "mẩu thừa" nào không.
3. **Quyết định (`if-else`):**
* Nếu không thừa (`% == 0`): Giữ nguyên kết quả chia.
* Nếu có thừa (bất kể ít hay nhiều): Buộc phải cộng thêm 1 đơn vị để chứa nốt phần thừa đó.



### Tại sao cách này tốt cho người mới học?

* **Rõ ràng:** Nó mô tả đúng cách chúng ta suy nghĩ ngoài đời thực.
* **An toàn:** Tránh được sai số thập phân (số `float` hoặc `double` đôi khi tính toán không chính xác tuyệt đối với số rất lớn).

### Mở rộng: Cách viết tắt "Dân chuyên Tin"

Sau này khi quen rồi, bạn có thể thấy một công thức toán học gom 2 trường hợp `if-else` này lại làm một, kết quả tương đương:

* Nếu  chia hết cho  (ví dụ 10 chia 5):  (đúng).
* Nếu  dư 1 (ví dụ 11 chia 5):  (đúng, tự động nhảy lên).

Tuy nhiên, với cấp 2, cách dùng `if-else` như bạn viết là **trực quan nhất và tốt nhất** để hiểu bản chất vấn đề!