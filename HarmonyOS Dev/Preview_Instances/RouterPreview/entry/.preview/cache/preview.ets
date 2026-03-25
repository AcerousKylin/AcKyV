struct preview{build(){Text(`${this.content}`)
        .fontSize(50)
        .onClick(() => {
          this.secondaryData = (this.data["array"][2]).toString()
        })
        .margin({ top: 20})}}