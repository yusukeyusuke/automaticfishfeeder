# automaticfishfeeder
This is a servo control project for automatic feeders.

## ビルド環境
- Arduino 1.8.1
- 「スケッチ - ライブラリをインクルード - ライブラリを管理」からMsTimer2をインストール
- 「スケッチ - ライブラリをインクルード - .zip形式のライブラリをインストール」から、次のURLからダウンロードしたライブラリをインストール https://codeload.github.com/adafruit/Adafruit-PWM-Servo-Driver-Library/zip/master

## パラメータ
- now = 15 で電源ONされた時間を15時に設定
- MsTimer2::setで1時間(36000000UL)ごとにflagtimer()を呼び出すように設定
- now++で1時間経過をカウント
- 9時もしくは15時だったらdoFeed=1で餌やりを指示

![circuit](https://raw.githubusercontent.com/yusukeyusuke/automaticfishfeeder/master/automaticfeeder-circuit.png)
