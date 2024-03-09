from application import Application

if __name__ == '__main__':
    
    try:
        game = Application()
        game.start()

        while True:
            game.run()

    except KeyboardInterrupt:
        pass