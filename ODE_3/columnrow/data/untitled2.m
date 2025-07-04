% データの読み込み
data = load('data2.dat');

% x, yデータの抽出
x = data(:, 1); % 1列目をxデータとする
y = data(:, 2); % 2列目をyデータとする

% グラフの作成
figure;
plot(x, y, 'b-', 'LineWidth', 2); % 青色の線でプロット
xlabel('Xデータ');
ylabel('Yデータ');
title('XとYのデータプロット');
grid on; % グリッドを表示