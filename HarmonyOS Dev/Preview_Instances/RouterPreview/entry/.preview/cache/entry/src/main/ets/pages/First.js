import router from '@ohos:router';
class First extends ViewPU {
    constructor(parent, params, __localStorage, elmtId = -1) {
        super(parent, __localStorage, elmtId);
        this.setInitiallyProvidedValue(params);
    }
    setInitiallyProvidedValue(params) {
    }
    updateStateVars(params) {
    }
    purgeVariableDependenciesOnElmtId(rmElmtId) {
    }
    aboutToBeDeleted() {
        SubscriberManager.Get().delete(this.id__());
        this.aboutToBeDeletedInternal();
    }
    async routePage() {
        let options = {
            url: 'pages/Second',
            params: {
                text: "This is a value from Page 1.",
                data: {
                    array: [12, 48, 58]
                }
            }
        };
        try {
            await router.pushUrl(options);
        }
        catch (error) {
            console.info(` fail callback, code: ${error.code}, msg: ${error.msg}`);
        }
    }
    initialRender() {
        this.observeComponentCreation((elmtId, isInitialRender) => {
            ViewStackProcessor.StartGetAccessRecordingFor(elmtId);
            Flex.create({
                direction: FlexDirection.Column,
                alignItems: ItemAlign.Center,
                justifyContent: FlexAlign.Center
            });
            Flex.debugLine("pages/First.ets(28:5)");
            Flex.width("100%");
            Flex.height("100%");
            if (!isInitialRender) {
                Flex.pop();
            }
            ViewStackProcessor.StopGetAccessRecording();
        });
        this.observeComponentCreation((elmtId, isInitialRender) => {
            ViewStackProcessor.StartGetAccessRecordingFor(elmtId);
            Text.create("This is Page 1");
            Text.debugLine("pages/First.ets(33:7)");
            Text.fontSize(50);
            Text.fontWeight(FontWeight.Bold);
            if (!isInitialRender) {
                Text.pop();
            }
            ViewStackProcessor.StopGetAccessRecording();
        });
        Text.pop();
        this.observeComponentCreation((elmtId, isInitialRender) => {
            ViewStackProcessor.StartGetAccessRecordingFor(elmtId);
            Button.createWithChild();
            Button.debugLine("pages/First.ets(37:7)");
            Button.type(ButtonType.Capsule);
            Button.margin({ top: 20 });
            Button.backgroundColor("#ccc");
            Button.onClick(() => {
                this.routePage();
            });
            if (!isInitialRender) {
                Button.pop();
            }
            ViewStackProcessor.StopGetAccessRecording();
        });
        this.observeComponentCreation((elmtId, isInitialRender) => {
            ViewStackProcessor.StartGetAccessRecordingFor(elmtId);
            Text.create("New Page");
            Text.debugLine("pages/First.ets(38:9)");
            Text.fontSize(25);
            Text.fontWeight(FontWeight.Bold);
            if (!isInitialRender) {
                Text.pop();
            }
            ViewStackProcessor.StopGetAccessRecording();
        });
        Text.pop();
        Button.pop();
        Flex.pop();
    }
    rerender() {
        this.updateDirtyElements();
    }
}
ViewStackProcessor.StartGetAccessRecordingFor(ViewStackProcessor.AllocateNewElmetIdForNextComponent());
loadDocument(new First(undefined, {}));
ViewStackProcessor.StopGetAccessRecording();
//# sourceMappingURL=First.js.map