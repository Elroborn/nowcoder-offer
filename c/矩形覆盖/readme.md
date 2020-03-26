开始分析，主要看到有一个n是不断增加的，则肯定要考虑最终结果和n的关系。

当n = 1 的时候，很好分析，就1种结果
当n = 2时，则两种结果。
关键时n = 3时的分析，我们可以考虑第一个放的方块，如果这个方块时竖着放置，则剩下的有n-1，也就是f(n-1)种结果。
如果方块是横着放，则剩下的有n-2，也就是f(n-2)种结果，则f(3) = f(2) +f(1)种结果。  

///

<div class="answer-brief nc-post-content"><div>  依旧是斐波那契数列 </div>
<div>  2*n的大矩形，和n个2*1的小矩形 </div>
<div>  其中target*2为大矩阵的大小 </div>
<div>  有以下几种情形： </div>
<div>  1⃣️target &lt;= 0 大矩形为&lt;= 2*0,直接return 1； </div>
<div>  2⃣️target = 1大矩形为2*1，只有一种摆放方法，return1； </div>
<div>  3⃣️target = 2 大矩形为2*2，有两种摆放方法，return2； </div>
<div>  4⃣️target = n 分为两步考虑： </div>
<div>  &nbsp;&nbsp;&nbsp;&nbsp;&nbsp; &nbsp; 第一次摆放一块 2*1 的小矩阵，则摆放方法总共为f(target - 1)  <table border="1" cellpadding="2" cellspacing="0">
    <tbody>
      <tr>
        <td>      √     </td><td><br>
        </td><td><br>
        </td><td><br>
        </td><td><br>
        </td><td><br>
        </td><td><br>
        </td><td><br>
        </td></tr>
      <tr>
        <td>      √     </td><td><br>
        </td><td><br>
        </td><td><br>
        </td><td><br>
        </td><td><br>
        </td><td><br>
        </td><td><br>
        </td></tr>
    </tbody>
  </table>
  <br>第一次摆放一块1*2的小矩阵，则摆放方法总共为f(target-2) </div>
<div>  因为，摆放了一块1*2的小矩阵（用√√表示），对应下方的1*2（用××表示）摆放方法就确定了，所以为f(targte-2) </div>
<div>
  <table border="1" cellpadding="2" cellspacing="0">
    <tbody>
      <tr>
        <td>      √     </td><td>      √     </td><td><br>
        </td><td><br>
        </td><td><br>
        </td><td><br>
        </td><td><br>
        </td><td><br>
        </td></tr>
      <tr>
        <td>      ×     </td><td>      ×     </td><td><br>
        </td><td><br>
        </td><td><br>
        </td><td><br>
        </td><td><br>
        </td><td><br>
        </td></tr>
    </tbody>
  </table>
  <br> 代码：<br>
</div>
<div><div id="highlighter_23247" class="syntaxhighlighter  java"><div class="toolbar" style="display:none;"></div><table border="0" cellpadding="0" cellspacing="0"><tbody><tr><td class="gutter"><div class="line number1 index0 alt2">1</div><div class="line number2 index1 alt1">2</div><div class="line number3 index2 alt2">3</div><div class="line number4 index3 alt1">4</div><div class="line number5 index4 alt2">5</div><div class="line number6 index5 alt1">6</div><div class="line number7 index6 alt2">7</div><div class="line number8 index7 alt1">8</div><div class="line number9 index8 alt2">9</div><div class="line number10 index9 alt1">10</div><div class="line number11 index10 alt2">11</div><div class="line number12 index11 alt1">12</div><div class="line number13 index12 alt2">13</div><div class="line number14 index13 alt1">14</div></td><td class="code"><div class="container"><div class="line number1 index0 alt2"><code class="java keyword">public</code> <code class="java keyword">class</code> <code class="java plain">Solution {</code></div><div class="line number2 index1 alt1"><code class="java spaces">&nbsp;&nbsp;&nbsp;&nbsp;</code><code class="java keyword">public</code> <code class="java keyword">int</code> <code class="java plain">RectCover(</code><code class="java keyword">int</code> <code class="java plain">target) {</code></div><div class="line number3 index2 alt2"><code class="java spaces">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;</code><code class="java keyword">if</code><code class="java plain">(target&nbsp; &lt;= </code><code class="java value">1</code><code class="java plain">){</code></div><div class="line number4 index3 alt1"><code class="java spaces">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;</code><code class="java keyword">return</code> <code class="java value">1</code><code class="java plain">;</code></div><div class="line number5 index4 alt2"><code class="java spaces">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;</code><code class="java plain">}</code></div><div class="line number6 index5 alt1"><code class="java spaces">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;</code><code class="java keyword">if</code><code class="java plain">(target*</code><code class="java value">2</code> <code class="java plain">== </code><code class="java value">2</code><code class="java plain">){</code></div><div class="line number7 index6 alt2"><code class="java spaces">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;</code><code class="java keyword">return</code> <code class="java value">1</code><code class="java plain">;</code></div><div class="line number8 index7 alt1"><code class="java spaces">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;</code><code class="java plain">}</code><code class="java keyword">else</code> <code class="java keyword">if</code><code class="java plain">(target*</code><code class="java value">2</code> <code class="java plain">== </code><code class="java value">4</code><code class="java plain">){</code></div><div class="line number9 index8 alt2"><code class="java spaces">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;</code><code class="java keyword">return</code> <code class="java value">2</code><code class="java plain">;</code></div><div class="line number10 index9 alt1"><code class="java spaces">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;</code><code class="java plain">}</code><code class="java keyword">else</code><code class="java plain">{</code></div><div class="line number11 index10 alt2"><code class="java spaces">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;</code><code class="java keyword">return</code> <code class="java plain">RectCover((target-</code><code class="java value">1</code><code class="java plain">))+RectCover(target-</code><code class="java value">2</code><code class="java plain">);</code></div><div class="line number12 index11 alt1"><code class="java spaces">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;</code><code class="java plain">}</code></div><div class="line number13 index12 alt2"><code class="java spaces">&nbsp;&nbsp;&nbsp;&nbsp;</code><code class="java plain">}</code></div><div class="line number14 index13 alt1"><code class="java plain">}</code></div></div></td></tr></tbody></table></div></div>
<br></div>