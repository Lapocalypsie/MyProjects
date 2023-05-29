import { useRouter } from "next/router";
import Editor from "../components/Editor";
import styles from "../styles/Editor.module.css";
import PropTypes from "prop-types";
import { useState } from "react";

export default function SimplepediaCreator({ setCurrentArticle }) {
  const router = useRouter();
  const [article, setArticle] = useState(null);

  async function complete(newArticle) {
    if (newArticle) {
      const response = await fetch(`/api/articles`, {
        method: "POST",
        body: JSON.stringify(newArticle),
        headers: new Headers({
          Accept: "application/json",
          "Content-Type": "application/json",
        }),
      });
      const createdArticle = await response.json();
      setCurrentArticle(createdArticle);
      //Since we are pushing from this component, we need a way to set the article and render it for the editor component.
      setArticle(createdArticle);
      router.push(`/articles/${createdArticle.id}`);
    } else {
      // User canceled, go back to previous page
      router.back();
    }
  }

  return (
    <div className={styles.Editor}>
      <Editor article={article} complete={complete} />
    </div>
  );
}

SimplepediaCreator.propTypes = {
  setCurrentArticle: PropTypes.func.isRequired,
};
