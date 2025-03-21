import yfinance as yf
import sys

def get_stock_price(symbol):
    """fetch stock price from yahoo finance"""
    stock = yf.Ticker(symbol)
    return stock.history(period="1m")['Close'].iloc[-1]

if __name__ == "__main__":
    if len(sys.argv) < 2:
        print("usage: python3 yahoo_data.py <symbol>")
        sys.exit(1)

    symbol = sys.argv[1]
    price = get_stock_price(symbol)
    print(price)
